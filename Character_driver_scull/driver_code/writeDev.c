#include"headers.h"
#include"fileopr.h"
#include"declarations.h"

ssize_t writeDev(struct file* filep,const char __user *ubuff,size_t size,loff_t *lseek)
{
	struct Qset *lqset;
	int noctw,cret=0;
	int nocaw=0;
	int i=0;
	struct Dev *ldev;
	size_t lsize;
	#ifdef DEBUG
	printk(KERN_INFO "%s started\n",__func__);
	#endif
	lqset=(void*)0;
	ldev=(void*)0;
	ldev= filep->private_data;
	if( !ldev ) {
		#ifdef DEBUG
		printk(KERN_ERR "%s error from private_data",__func__);
		#endif
	}

	if( size > Device_Size) {
		#ifdef DEBUG
		printk(KERN_INFO "%s Partial writing possible\n",__func__);
		#endif
		noctw=lsize = Device_Size;
	}
	else
		noctw=lsize = size;
	
	


	if(down_interruptible(&ldev->sem))
		return -ERESTARTSYS;

	ldev->start= createScull(lsize);		// creating SCULL. After this we can begin writing.
	lqset = ldev->start;
	/************************************************************************************************************************************/
	while(noctw)
	{
		if(noctw > ldev->size_of_reg)
			noctw=ldev->size_of_reg;
		cret = copy_from_user(lqset->data[i],ubuff+nocaw,noctw);
		if(cret==-1) {
			#ifdef DEBUG
			printk(KERN_INFO "%s copy_from_user error\n",__func__);
			#endif
		}
		
//		printk(KERN_INFO "%s > %s\n",__func__,(char*)lqset->data[i]);
		nocaw = nocaw + (noctw - cret);
		Data_Size = nocaw;
		noctw = lsize - nocaw;
		i++;
		if( i == No_Of_Reg) {
			i=0;
			lqset=lqset->next;
		}
//	printk(KERN_INFO "%s nocaw = %d\n",__func__,nocaw);
//	printk(KERN_INFO "%s noctw = %d\n",__func__,noctw);

	}
	/*************************************************************************************************************************************/
	ldev->data_size = Data_Size;
	up(&ldev->sem);
//	printk(KERN_INFO "%s cret = %d\n",__func__,cret);
	#ifdef DEBUG
	printk(KERN_INFO "%s finished\n",__func__);
	#endif
	return nocaw;
}
