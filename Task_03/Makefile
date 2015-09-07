ifneq ($(KERNELRELEASE),)
obj-m := hello_version.o
else
#KDIR ?= $(HOME)/Sources/linux
KDIR ?= /lib/modules/`uname -r`/build
all:
	$(MAKE) -C $(KDIR) M=$$PWD
endif
