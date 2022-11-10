
obj-m += static_allocation.o
obj-m += dynamic_allocation.o
KERNEL_DIR = /lib/modules/$(shell uname -r)/build
CURRENT_DIR = $(shell pwd)

all:
	make -C $(KERNEL_DIR)  M=$(CURRENT_DIR) modules

clean:
	make -C $(KERNEL_DIR)  M=$(CURRENT_DIR) clean
