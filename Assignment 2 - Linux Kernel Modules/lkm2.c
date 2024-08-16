#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched/signal.h>
#include <linux/mm_types.h>

MODULE_DESCRIPTION("Hello kernel module lkm2");
MODULE_AUTHOR("Shivansh Dhiman");
MODULE_LICENSE("GPL");

struct task_struct *task;

static int hello_module_init(void) { 
    struct task_struct *max_heap_task = NULL;
    unsigned long max_heap_size = 0, heap;
    for_each_process(task) {
        struct mm_struct *mm = task->mm;
        if (!mm) {
            continue;
        }
        // heap = mm->total_vm - mm->data_vm - mm->exec_vm - mm->stack_vm;
        heap = (mm->brk - mm->start_brk);
        if (heap > max_heap_size) {
            max_heap_size = heap;
            max_heap_task = task;
        }
    }
    printk(KERN_INFO "Task with maximum heap size is:\n");
    printk(KERN_INFO "PID: %d\n", max_heap_task->pid);
    printk(KERN_INFO "Heap size: %ld\n", max_heap_size);
    return 0;
}

static void hello_module_exit(void) {
    printk(KERN_INFO "Exiting module\n");
}

module_init(hello_module_init);
module_exit(hello_module_exit);
