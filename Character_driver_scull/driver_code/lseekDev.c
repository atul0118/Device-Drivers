#include"headers.h"
#include"fileopr.h"
#include"declarations.h"

loff_t lseekDev(struct file* filep, loff_t offset,int pos)
{	
	printk(KERN_INFO "%s: started\n",__func__);
	switch(pos) {
		case 0:
			#ifdef DEBUG
			printk(KERN_INFO "%s: SEEK_SET and offset received %d\n",__func__,(int)offset);
			#endif
			if(offset >= Data_Size) {
				#ifdef DEBUG
				printk(KERN_ERR "%s: Cannot take offset larger than data on device\n",__func__);
				#endif
				return (loff_t)-1;
			}

			filep->f_pos = offset;
			break;
		case 1:
			#ifdef DEBUG
			printk(KERN_INFO "%s: SEEK_CUR\n",__func__);
			#endif
			break;
		case 2:
			#ifdef DEBUG
			printk(KERN_INFO "%s: SEEK_END\n",__func__);
			#endif
	}

	printk(KERN_INFO "%s: finished\n",__func__);
	return filep->f_pos;
}
