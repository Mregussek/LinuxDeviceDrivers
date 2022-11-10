
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mateusz Rzeczyca");
MODULE_DESCRIPTION("Template!");
MODULE_VERSION("1:0.1-template");


static int __init template_init(void)
{
    pr_info("Template Inserted Successfully...\n");
    return 0;
}


static void __exit template_exit(void)
{
    pr_info("Template saying goodbye...\n");
}


module_init(template_init);
module_exit(template_exit);
 