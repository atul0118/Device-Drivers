#include"headers.h"
#include"declarations.h"
//#include"fileopr.h"
int major_num,minor_num,Size_Of_Reg,Device_Size,No_Of_Reg,Data_Size;
struct file_operations fops= {
open: openDev,
release: releaseDev,
read: readDev,
write: writeDev,
llseek: lseekDev
};
module_param(nod,int,S_IRUGO);
dev_t dev_id,dev_number;
struct Dev *dev;
EXPORT_SYMBOL(wow_module);
static int __init driver_init_func(void)
{
	int ret;
	int l=0;
	initialization();
	#ifdef DEBUG
	printk(KERN_INFO ">>> Hey Atul!!!!\n");
	#endif
	ret=alloc_chrdev_region(&dev_id,0,nod,DEV_NAME);
	if(ret==-1) {
		#ifdef	DEBUG
		printk(KERN_ERR "alloc_chrdev_region() failure\n");
		#endif
		return -1;
	}
	major_num=MAJOR(dev_id);
	minor_num=MINOR(dev_id);
	dev=(struct Dev*)kmalloc(sizeof(struct Dev)*nod,GFP_KERNEL);
	if (!dev) {
		#ifdef DEBUG
		printk(KERN_ERR "kmalloc error\n");
		#endif
		return -1;
	}

	// memset struct Dev //


/*	major_num=register_chrdev(0,"ghost",&fops);
	if(major_num==-1) {
		printk(KERN_ERR "register_chrdev() failed\n");
		return -1;
	}*/
	#ifdef	DEBUG
	printk(KERN_INFO "Major no. %d \nMinor no. %d and Nod = %d\n",major_num,minor_num,nod);
	#endif

	for(l=0;l<nod;l++) {
		cdev_init(&dev[l].c_dev,&fops);
		sema_init(&dev[l].sem,1);
		cdev_add(&dev[l].c_dev,dev_id,1);
		dev[l].c_dev.ops=&fops;
		dev[l].no_of_reg= No_Of_Reg;
		dev[l].size_of_reg= Size_Of_Reg;
		dev[l].data_size= Data_Size;
		dev[l].device_size= Device_Size;
		dev_number=MKDEV(major_num,l);				// combines major number and minor number to create device unique id.
		minor_num=MINOR(dev_number);
		#ifdef DEBUG
		printk(KERN_INFO "minor number %d\n",minor_num);
		#endif
	}

	return 0;
}

module_init(driver_init_func);
