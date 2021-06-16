#include"headers.h"
#include"declarations.h"

struct Qset* createScull(size_t dsize)
{
	int noi,noq,ghost_noq,i;					// number of items required and number of quantums.
	int l;
	struct Qset *lqset,*ghost_lqset;					// Beginning of our linked list. INfact 2nd node.
	struct Qset *start;
	printk(KERN_INFO "%s started\n",__func__);
	ghost_noq = 0;
	start = (void*)0;						// to avoid wild pointer
	lqset = (void*)0;		
	ghost_lqset=(void*)0;
	noi = (dsize) / (No_Of_Reg * Size_Of_Reg);
	if( ((dsize)%(No_Of_Reg * Size_Of_Reg)) != 0)
		noi++;
	noq = (dsize) / (Size_Of_Reg);
	if( ((dsize)%(Size_Of_Reg)) != 0)
		noq++;

	for(l=0;l<noi;l++) {
		if (l==0) {
//			printk(KERN_INFO "%s 1st item created\n",__func__);
			start = lqset = ghost_lqset= (struct Qset*)kmalloc(sizeof(struct Qset),GFP_KERNEL); 		// Node created
			if( !lqset ) {
				#ifdef DEBUG
				printk(KERN_ERR "Error from createScull()\n");
				#endif
			}
			memset(lqset, '\0' , sizeof(struct Qset));					// Making Pointers equals to NULL
		}
		else {
//			printk(KERN_INFO "%s 2nd item created\n",__func__);
			lqset->next=(struct Qset*)kmalloc(sizeof(struct Qset),GFP_KERNEL); 		// Node created
			if( !lqset ) {
				#ifdef DEBUG
				printk(KERN_ERR "Error from createScull()\n");
				#endif
			}
			lqset=lqset->next;
			memset(lqset, '\0' , sizeof(struct Qset));					// Making Pointers equals to NULL
			//ghost_lqset->next=lqset;
	//		ghost_lqset=ghost_lqset->next;
		}
	}
	lqset=start;
	for(l=0;l<noi;l++) {
		lqset->data=kmalloc(sizeof(char*) * No_Of_Reg,GFP_KERNEL);		// Making array of pointers
		if( !lqset->data ) {
			#ifdef DEBUG
			printk(KERN_ERR "Error from createScull()\n");
			#endif
		}
		memset(lqset->data ,'\0',sizeof(char*)* No_Of_Reg);				// Making each quantum value as NULL.
		lqset=lqset->next;
//	printk(KERN_INFO "%s quantum set created\n",__func__);						// BREAKPOINT//
	}

	lqset=start;

	while(1)
	{
		for(i=0; i<(No_Of_Reg);i++) {
//			printk(KERN_INFO "%s quantums created\n",__func__);						// BREAKPOINT//
			lqset->data[i]=(char*)kmalloc(sizeof(char)*Size_Of_Reg,GFP_KERNEL);
			if( !lqset->data[i] ) {
				#ifdef DEBUG
				printk(KERN_ERR "Error from createScull()\n");
				#endif
			}
			memset(lqset->data[i] ,'\0',sizeof(char)* Size_Of_Reg);				// Making each quantum value as NULL.
		}
		if(lqset->next == (void*)0) {
			break;
		}
		lqset=lqset->next;
	}
	
	printk(KERN_INFO "Scull created successfully\n");
	return start;
	
}


