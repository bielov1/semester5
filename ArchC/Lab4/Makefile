ifneq ($(KERNELRELEASE),)
# kbuil part of makefile
obj-m := hello1.o hello2.o
#path to hello1.h
#ccflags-y := -I$(PWD)/inc             NOT WORKING!
else
# normal makefile
KDIR ?= /lib/modules/`uname -r`/build

default:
	$(MAKE) -C $(KDIR) M=$$PWD ccflags-y=-I$(PWD)/inc modules
clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
endif
