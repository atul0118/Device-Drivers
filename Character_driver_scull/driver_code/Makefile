INSTALL_DIR=final_module
ifneq (${KERNELRELEASE},)
	obj-m :=my_module.o

my_module-objs := init.o clean.o initialization.o openDev.o releaseDev.o clear_device.o readDev.o writeDev.o createScull.o lseekDev.o 

else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
default:
	$(MAKE)  -C $(KERNELDIR) M=$(PWD) modules
	@rm -rf ${INSTALL_DIR}
	@mkdir ${INSTALL_DIR}
	@mv -f *.o *.ko *.mod.c .*.cmd ${INSTALL_DIR}
clean:
	rm -rf ${INSTALL_DIR}
endif
