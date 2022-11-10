
# Hello Parameters

```bash
sudo make
sudo insmod hello_parameters.ko value_int=7 value_arr=17,172,1730,17400 value_name="Mateusz"
dmesg
lsmod
modinfo hello_parameters.ko
sudo rmmod hello_parameters.ko
dmesg
```
