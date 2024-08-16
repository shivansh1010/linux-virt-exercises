#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/syscalls.h>
#include <linux/mm.h>
#include <linux/sched/signal.h>
#include <linux/sched/task.h>

MODULE_DESCRIPTION("Hello kernel module lkm4");
MODULE_AUTHOR("Shivansh Dhiman");
MODULE_LICENSE("GPL");

int pid = 1;
unsigned long vaddr = 0, paddr = 0;
module_param(pid, int, 0660);
module_param(vaddr, long, 0664);

struct task_struct *task;
struct mm_struct *mm;

unsigned long convert(struct mm_struct *mm, unsigned long virtual_addr) {
    unsigned long physical_addr;
    unsigned long pfn;
    pgd_t *pgd;
    p4d_t *p4d;
    pud_t *pud;
    pmd_t *pmd;
    pte_t *ptep;

    pgd = pgd_offset(mm, virtual_addr);
    if (!pgd_present(*pgd)) return 0;
    p4d = p4d_offset(pgd, virtual_addr);
    if (!p4d_present(*p4d)) return 0;
    pud = pud_offset(p4d, virtual_addr);
    if (!pud_present(*pud)) return 0;
    pmd = pmd_offset(pud, virtual_addr);
    if (!pmd_present(*pmd)) return 0;
    ptep = pte_offset_kernel(pmd, virtual_addr);
    if (!ptep || !pte_present(*ptep)) return 0;

    // printk(KERN_INFO "pgd: \t\t%p\n", pgd);
    // printk(KERN_INFO "p4d: \t\t%p\n", p4d);
    // printk(KERN_INFO "pud: \t\t%p\n", pud);
    // printk(KERN_INFO "pmd: \t\t%p\n", pmd);
    // printk(KERN_INFO "pte: \t\t%p\n", pte);
    // printk(KERN_INFO "pfn: \t\t%ld\n", pfn);

    pfn = pte_pfn(*ptep);
    physical_addr = pfn << PAGE_SHIFT;
    return physical_addr | (virtual_addr & ~PAGE_MASK);
}

static int hello_module_init(void) { 
    
    for_each_process(task)
        if (task->pid == pid)
            break;
    mm = task->mm;

    if (mm && mm->start_brk && vaddr == 0) {
        vaddr = mm->start_brk;
    }

    paddr = convert(mm, vaddr);

    printk(KERN_INFO "PID:%d\n", pid);
    printk(KERN_INFO "Virtual addr:\t0x%lx\n", vaddr);
    if (paddr == 0) {
        printk(KERN_INFO "Physical addr: \tNot Found\n");
    } else {
        printk(KERN_INFO "Physical addr: \t0x%lx\n", paddr);
    }
    return 0;
}

static void hello_module_exit(void) {
    printk(KERN_INFO "Exiting module\n");
}

module_init(hello_module_init);
module_exit(hello_module_exit);
