#include"headers.h"
#include"fileopr.h"
#include"declarations.h"

int releaseDev(struct inode* in, struct file* f)
{	
	printk(KERN_INFO "%s started\n",__func__);
	printk(KERN_INFO "%s finished\n",__func__);
	return 0;
}
