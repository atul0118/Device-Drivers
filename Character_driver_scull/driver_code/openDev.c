#include"headers.h"
#include"fileopr.h"
#include"declarations.h"

int openDev(struct inode* inp, struct file* fp)
{
	int cret;
	struct Dev *ldev;
	printk(KERN_INFO "%s started\n",__func__);
	ldev=container_of(inp->i_cdev,struct Dev,c_dev); 			// long story
	if(!ldev) {
		#ifdef DEBUG
		printk(KERN_ERR "container_of failure\n");
		#endif
		return -1;
	}
	if((fp->f_flags & O_ACCMODE) == O_WRONLY) {
		cret=clear_device(ldev);
		if(cret == -1) {
			#ifdef DEBUG
			printk(KERN_ERR "container_of failure\n");
			#endif
			return -1;
		}
	}
	fp->private_data=ldev;
		
	printk(KERN_INFO "%s finished\n",__func__);
	return 0;
}
