
# Hello Parameters

```bash
sudo make
sudo insmod hello_parameters.ko value_int=7 value_arr=17,172,1730,17400 value_name="Mateusz"

dmesg
cd /sys/module/hello_parameters/parameters
sudo cat value_arr
sudo cat value_int
sudo cat value_name

sudo cat value_int_cb
sudo sh -c "echo 21 > /sys/module/hello_parameters/parameters/value_int_cb"
sudo cat value_int_cb
dmesg

sudo rmmod hello_parameters.ko
dmesg
```
