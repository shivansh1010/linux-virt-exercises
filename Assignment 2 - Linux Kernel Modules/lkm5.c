#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/mm.h>
#include <linux/mm_types.h>
#include <linux/sched/task.h>

MODULE_DESCRIPTION("Hello kernel module lkm5");
MODULE_AUTHOR("Shivansh Dhiman");
MODULE_LICENSE("GPL");

static int pid = 1;
module_param(pid, int, 0660);

struct task_struct *task;
struct mm_struct *mm;
struct vm_area_struct *vma;

static int hello_module_init(void) { 
    unsigned long total_vmem = 0;
    unsigned long total_pmem = 0;

    for_each_process(task) {
        if (task->pid == pid) {
            break;
        }
    }
    mm = task->mm;
    for (vma = mm->mmap ; vma ; vma = vma->vm_next) {
        total_vmem += vma->vm_end - vma->vm_start;
    } 
    total_pmem = get_mm_rss(mm);

    printk(KERN_INFO "Virtual address space: %ld\n", total_vmem);
    // printk(KERN_INFO "Virtual address space (mm): %ld\n", mm->total_vm * PAGE_SIZE);
    printk(KERN_INFO "Physical address space: %ld\n", total_pmem * PAGE_SIZE);

    return 0;
}

static void hello_module_exit(void) {
    printk(KERN_INFO "Exiting module\n");
}

module_init(hello_module_init);
module_exit(hello_module_exit);
