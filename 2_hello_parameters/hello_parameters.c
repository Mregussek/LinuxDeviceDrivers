
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mateusz Rzeczyca");
MODULE_DESCRIPTION("Hello Parameters!");
MODULE_VERSION("1:0.1-helloparameters");

int value_int;
int value_arr[4];
char* value_name;
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
int set_notify_param_cb(const char *val, const struct kernel_param *kp)
{
    int res = param_set_int(val, kp);
    if (res == 0) {
        pr_info("Callback setter function called in order to notify kernel that value has changed...\n");
        pr_info("New value of value_int_cb = %d\n", value_int_cb);
        return 0;
    }
    pr_err("Callback setter function failed! Cannot update value_int_cb!\n");
    return -1;
}


const struct kernel_param_ops my_param_ops = 
{
    .set = &set_notify_param_cb,
    .get = &param_get_int,
};


module_param_cb(value_int_cb, &my_param_ops, &value_int_cb, S_IRUGO | S_IWUSR);


static void display_arr(int* arr, int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        pr_info("value_arr[%d] = %d\n", i, arr[i]);
    }
}


static int __init hello_parameters_init(void)
{
    pr_info("value_int = %d \n", value_int);
    display_arr(value_arr, sizeof(value_arr) / sizeof (int));
    pr_info("value_name = %s \n", value_name);
    pr_info("value_int_cb = %d \n", value_int_cb);

    pr_info("Hello Parameters Inserted Successfully...\n");
    return 0;
}


static void __exit hello_parameters_exit(void)
{
    pr_info("Hello Parameters saying goodbye...\n");
}


module_init(hello_parameters_init);
module_exit(hello_parameters_exit);
 