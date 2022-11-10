
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mateusz Rzeczyca");
MODULE_DESCRIPTION("Hello Drivers!");
MODULE_VERSION("1:0.2-helloparameters");

int value_int = 0;
int value_arr[4];
char* value_name = "";
int value_int_cb = 0;
 
// /sys/module/hello_parameters/parameters/value_int
module_param(value_int, int, S_IRUSR | S_IWUSR);

// /sys/module/hello_parameters/parameters/value_name
module_param(value_name, charp, S_IRUSR | S_IWUSR);

// /sys/module/hello_parameters/parameters/value_arr
module_param_array(value_arr, int, NULL, S_IRUSR | S_IWUSR);
 

// struct kernel_param_ops 
// {
//     int (*set)(const char *val, const struct kernel_param *kp);
//     int (*get)(char *buffer, const struct kernel_param *kp);
//     void (*free)(void *arg);
// };


// Only cb params can be notified about value change
int set_notify_param_cb(const char* val, const struct kernel_param* kp)
{
    int res = param_set_int(val, kp);
    if (res == 0) {
        printk(KERN_INFO "Callback setter function called in order to notify kernel that value has changed...\n");
        printk(KERN_INFO "New value of value_int_cb = %d\n", value_int_cb);
        return 0;
    }
    printk(KERN_ERR, "Callback setter function failed! Cannot update value_int_cb!\n");
    return -1;
}


const struct kernel_param_ops my_param_ops = 
{
    .set = &set_notify_param_cb,
    .get = &param_get_int,
};


module_param_cb(value_int_cb, &my_param_ops, &value_int_cb, S_IRGRP | S_IWUSR );


static int __init hello_parameters_init(void)
{
    printk(KERN_INFO "value_int = %d  \n", value_int);
    for (int i = 0; i < (sizeof(value_arr) / sizeof (int)); i++) {
        printk(KERN_INFO "value_arr[%d] = %d\n", i, value_arr[i]);
    }
    printk(KERN_INFO "value_name = %d  \n", value_name);
    printk(KERN_INFO "value_int_cb = %s \n", value_int_cb);

    printk(KERN_INFO "Hello Parameters Inserted Successfully...\n");
    return 0;
}


static void __exit hello_parameters_exit(void)
{
    printk(KERN_INFO "Hello Parameters saying goodbye...\n");
}


module_init(hello_parameters_init);
module_exit(hello_parameters_exit);
 