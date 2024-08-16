#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched/signal.h>

MODULE_DESCRIPTION("Hello kernel module lkm1");
MODULE_AUTHOR("Shivansh Dhiman");
MODULE_LICENSE("GPL");

struct task_struct *task;

static int hello_module_init(void) {
    printk(KERN_INFO "Printing running and runnable processes\n");
    for_each_process(task) {
        if (task->__state == 0)
            printk(KERN_INFO "%d\t%s\n", task->pid, task->comm);
    }
    return 0;
}

static void hello_module_exit(void) {
    printk(KERN_INFO "Exiting module\n");
}

module_init(hello_module_init);
module_exit(hello_module_exit);
