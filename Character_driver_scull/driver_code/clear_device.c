#include"headers.h"
#include"declarations.h"

int clear_device(struct Dev* ldev)
{
	#ifdef DEBUG
	printk(KERN_INFO "%s started\n",__func__);
	#endif
/*	if(!ldev) {
		#ifdef DEBUG
		printk(KERN_ERR "%s Sorry! Device not found\n",__func__);
		#endif
	}
	if(!ldev->first) {
		#ifdef DEBUG
		printk(KERN_ERR "%s Sorry! scull\n",__func__);
		#endif
	}
*/
	
	#ifdef DEBUG
	printk(KERN_INFO "%s finished\n",__func__);
	#endif
	return 0;
}
