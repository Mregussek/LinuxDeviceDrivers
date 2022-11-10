
# Hello Major Minor Numbers

```bash
cat /proc/devices
```

## Notes

The major number identifies the driver associated with the device.
Many devices may use the same major number. So we need to assign the number to each device that is using the same major number.
So, this is a minor number.
In other words, The device driver uses the minor number to distinguish individual physical or logical devices.

We can allocate the major and minor numbers in two ways:

- Statically allocating
- Dynamically Allocating

**Statically allocating**
If you want to set a particular major number for your driver, you can use this method.
This method will allocate that major number if it is available. Otherwise, it won’t.

```c
int register_chrdev_region(dev_t first, unsigned int count, char *name);
```

**Dynamically Allocating**
If we don’t want the fixed major and minor numbers please use this method. This method will allocate the major number dynamically to your driver which is available.

```c
int alloc_chrdev_region(dev_t *dev, unsigned int firstminor, unsigned int count, char *name);
```

**Unregister major minor numbers**

Regardless of how you allocate your device numbers, you should free them when they are no longer in use. Device numbers are freed with:

```c
void unregister_chrdev_region(dev_t first, unsigned int count);
```

**dev_t type description**

The dev_t type (defined in <linux/types.h>) is used to hold device numbers—both the major and minor parts.
dev_t is a 32-bit quantity with 12 bits set aside for the major number and 20 for the minor number.

```c
dev_t value_dev_t = MKDEV(int major, int minor);

int value_major = MAJOR(dev_t dev);
int value_minor = MINOR(dev_t dev);
```

## Example

Major numbers are returned by *cat /proc/devices*

```bash
Character devices:
  1 mem
  4 /dev/vc/0
  4 tty
  4 ttyS
  5 /dev/tty
  5 /dev/console
# ...

Block devices:
  7 loop
  8 sd
  9 md
 11 sr
 65 sd
# ...
```
