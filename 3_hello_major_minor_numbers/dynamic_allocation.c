
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mateusz Rzeczyca");
MODULE_DESCRIPTION("dynamic_allocation!");
MODULE_VERSION("1:0.3-dynamic_allocation");


dev_t value_dev = MKDEV(217, 0);


static int __init dynamic_allocation_init(void)
{
    int res = alloc_chrdev_region(&value_dev, 0, 1, "Mateusz");
    if (res < 0) {
        pr_err("Cannot allocate major number for device 1\n");
        return -1;
    }
    pr_info("Major = %d Minor = %d \n",MAJOR(value_dev), MINOR(value_dev));
    pr_info("dynamic_allocation Inserted Successfully...\n");
    return 0;
}


static void __exit dynamic_allocation_exit(void)
{
    unregister_chrdev_region(value_dev, 1);
    pr_info("dynamic_allocation saying goodbye...\n");
}


module_init(dynamic_allocation_init);
module_exit(dynamic_allocation_exit);
 