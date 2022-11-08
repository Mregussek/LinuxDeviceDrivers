
# Hello Drivers

```bash
sudo apt-get install build-essential
sudo make
sudo insmod hello_drivers.ko
dmesg
lsmod
modinfo hello_drivers.ko
sudo rmmod hello_drivers.ko
dmesg
```
