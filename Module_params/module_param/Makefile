INSTALL_DIR = new_module
ifneq (${KERNELRELEASE},)
	obj-m :=ghost.o

#ghost-objs := init.o clean.o initialization.o 
ghost-y := init.o 

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

