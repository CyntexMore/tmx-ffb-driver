ifneq ($(KERNELRELEASE),)
# kbuild part

KVERSION = $(shell uname -r)
#EXTRA_CFLAGS=-I$(KDIR)/drivers/hid

obj-m := tmx_driver.o

else

KVERSION = $(shell uname -r)
KDIR := /lib/modules/$(KVERSION)/build
MODULE_INSTALL_DIR := /lib/modules/$(KVERSION)/updates/tmx-ffb
MODS := tmx_driver.ko
PWD := $(shell pwd)

default:
    $(MAKE) -C $(KDIR) M=$(PWD)

clean:
    $(MAKE) -C $(KDIR) M=$(PWD) clean

install:
    $(MAKE) -C $(KDIR) M=$(PWD) modules_install

endif
