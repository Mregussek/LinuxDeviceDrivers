
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mateusz Rzeczyca");
MODULE_DESCRIPTION("Hello Drivers!");
MODULE_VERSION("1:0.1-hellodrivers");


static int __init hello_drivers_init(void)
{
    printk(KERN_INFO "Hello Drivers from Mateusz\n");
    return 0;
}


static void __exit hello_drivers_exit(void)
{
    printk(KERN_INFO "Goodbye Drivers from Mateusz\n");
}


module_init(hello_drivers_init);
module_exit(hello_drivers_exit);
