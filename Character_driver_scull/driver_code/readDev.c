#include"headers.h"
#include"fileopr.h"
#include"declarations.h"

ssize_t readDev(struct file* filp,char __user *ubuff,size_t usize,loff_t *loff)
{
	int nocsr,noctr,i,lsize,ret,uoffset,item,quant,mnoctr;
	struct Dev *ldev;
	struct Qset* lqset;
	i=noctr=nocsr=lsize=ret=uoffset=mnoctr=0 ;
	quant=item=1;
	lqset=(void*)0;
	ldev=(void*)0;
	#ifdef DEBUG
	printk(KERN_INFO "%s: started\n",__func__);
	#endif
	ldev=filp->private_data;
	if(!ldev) {
		#ifdef DEBUG
		printk(KERN_ERR "%s: No device found\n",__func__);
		#endif
	}
	lqset = ldev->start;
	if(!lqset) {
		#ifdef DEBUG
		printk(KERN_ERR "%s: No item found\n",__func__);
		#endif
	}
	lsize=usize;
	if(lsize > Data_Size) {
		#ifdef DEBUG
		printk(KERN_INFO "%s: Partial reading possible\n",__func__);
		#endif
		lsize = Data_Size;
	}

	//////////// USER - OFFSET OPERATION FOR SEEK_SET /////////////
	
	uoffset = *loff	;					// setting uoffset to *loff(from 'filep->f_pos' )
	noctr=mnoctr=lsize - uoffset;
	/* FINDING ITEM TO START WITH */
	if(uoffset >= (No_Of_Reg * Size_Of_Reg)) {
		while( uoffset >= (No_Of_Reg * Size_Of_Reg) ) {
//			printk(KERN_INFO "Finding Item to start with\n");
			lqset=lqset->next;
			item++;
			uoffset = uoffset - (No_Of_Reg * Size_Of_Reg) ; 	/* Final 'uoffset' will be OFFSET in the new quantum. */
		}
	}

//	printk(KERN_INFO "*** Item to start with is %d\n",item);
	/* FINDNG QUANTUM TO START WITH */
	if(uoffset >= Size_Of_Reg) {
		while( uoffset >= Size_Of_Reg ) {
			i++;
			quant++;
			uoffset = uoffset - Size_Of_Reg ;			/* Final 'uoffset' will be OFFSET in the new quantum. */ 
		}
	}

	/////////////////////////////////////////////
//	printk(KERN_INFO "*** quantum to start with is %d and i = %d\n",quant,i);
	#ifdef DEBUG
//	printk(KERN_INFO "%s: loff received %d",__func__,(int)*loff); 		// To remember that value of 'f_pos or loff' is not modified. An instance of that value is used here. 
	#endif
	
	if(down_interruptible(&ldev->sem))
		return -ERESTARTSYS;



	while(1) {
		if(lqset->data) {
			if(noctr > ldev->size_of_reg)
				noctr = ldev->size_of_reg - uoffset;
			ret=copy_to_user(ubuff+nocsr,lqset->data[i]+uoffset,noctr);
			if(ret==-1) {
				#ifdef DEBUG
				printk(KERN_ERR "%s: copy_to_user error\n",__func__);
				#endif
			}
//			printk(KERN_INFO "*** After copy_to_user and value of i = %d\n",i);
			nocsr = nocsr + (noctr-ret);
//			Data_Size = Data_Size - nocsr;
			noctr = mnoctr - nocsr;							// NOTE THIS //
			if(noctr==0)
				break;
			i++;									// ???????????????????????????????????????? //
			if ( i == No_Of_Reg) {
				i=0;
				lqset=lqset->next;
			}
		}
		uoffset=0;
	
	}

	up(&ldev->sem);
			
			
	#ifdef DEBUG
	printk(KERN_INFO "%s: finished\n",__func__);
	#endif
	return nocsr;
}
