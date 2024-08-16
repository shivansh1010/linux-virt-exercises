#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched/signal.h>
#include <linux/mm_types.h>

MODULE_DESCRIPTION("Hello kernel module lkm3");
MODULE_AUTHOR("Shivansh Dhiman");
MODULE_LICENSE("GPL");

struct task_struct *task;
// struct thread_struct ti;

static int hello_module_init(void) { 
    for_each_process(task) {
        if (task->pid == 1) {
            printk(KERN_INFO "PID: %d\n", task->pid);
            printk(KERN_INFO "Process name: %s\n", task->comm);
            printk(KERN_INFO "Kernel Stack pointer: %p\n", task->stack);
            // printk(KERN_INFO "Kernel Stack pointer: %p\n", task->thread.sp);

        }
    }
    return 0;
}

static void hello_module_exit(void) {
    printk(KERN_INFO "Exiting module\n");
}

module_init(hello_module_init);
module_exit(hello_module_exit);
