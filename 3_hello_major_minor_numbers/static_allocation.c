
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mateusz Rzeczyca");
MODULE_DESCRIPTION("static_allocation!");
MODULE_VERSION("1:0.3-static_allocation");


dev_t value_dev = MKDEV(217, 0);


static int __init static_allocation_init(void)
{
    register_chrdev_region(value_dev, 1, "Mateusz");
    pr_info("Major = %d Minor = %d \n",MAJOR(value_dev), MINOR(value_dev));
    pr_info("static_allocation Inserted Successfully...\n");
    return 0;
}


static void __exit static_allocation_exit(void)
{
    unregister_chrdev_region(value_dev, 1);
    pr_info("static_allocation saying goodbye...\n");
}


module_init(static_allocation_init);
module_exit(static_allocation_exit);
 