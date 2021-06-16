#include"headers.h"
#include"declarations.h"
static void __exit driver_clean_func(void)
{
	int l=0;
	printk(KERN_INFO ">>> Bye Atul!!!!\n");
	for(l=0;l<nod;l++) {
		cdev_del(&dev[l].c_dev);
	}
	cdev_del(&dev->c_dev);
	kfree(dev);
	unregister_chrdev_region(dev_id,nod);
}

module_exit(driver_clean_func);
