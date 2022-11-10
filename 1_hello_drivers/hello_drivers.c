
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mateusz Rzeczyca");
MODULE_DESCRIPTION("Hello Drivers!");
MODULE_VERSION("1:0.1-hellodrivers");


static int __init hello_drivers_init(void)
{
    printk(KERN_DEBUG "Debug Hello Drivers from Mateusz\n");
    printk(KERN_INFO "Info Hello Drivers from Mateusz\n");
    printk(KERN_NOTICE "Notice Hello Drivers from Mateusz\n");
    printk(KERN_WARNING "Warning Hello Drivers from Mateusz\n");
    printk(KERN_ERR "Error Hello Drivers from Mateusz\n");
    printk(KERN_CRIT "Critical Hello Drivers from Mateusz\n");
    printk(KERN_ALERT "Alert Hello Drivers from Mateusz\n");
    printk(KERN_EMERG "Emergency Hello Drivers from Mateusz\n");

    pr_info("Checking pr_info...");
    pr_cont("Continuing pr_info...");

    pr_debug("Checking pr_debug...");
    pr_cont("Continuing pr_debug...");

    pr_err("Checking pr_err...");
    pr_cont("Continuing pr_err...");

    pr_warn("Checking pr_warn...");
    pr_cont("Continuing pr_warn...");

    return 0;
}


static void __exit hello_drivers_exit(void)
{
    printk(KERN_INFO "Goodbye Drivers from Mateusz\n");
}


module_init(hello_drivers_init);
module_exit(hello_drivers_exit);
