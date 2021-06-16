#ifndef DEBUG
#define DEBUG
#endif

#ifndef DEVSIZE
#define DEVSIZE 1024
#endif

#ifndef REGSIZE
#define REGSIZE 4
#endif

#ifndef NUMOFREG
#define NUMOFREG 8
#endif

#ifndef DATASIZE
#define DATASIZE 0
#endif

#ifndef MAJOR_NUM
#define MAJOR_NUM 0
#endif

#ifndef MINOR_NUM
#define MINOR_NUM 0
#endif

#ifndef DEV_NAME
#define DEV_NAME "ghost_driver"
#endif

#ifndef DEV_NUM
#define DEV_NUM 1
#endif
extern int major_num,minor_num,nod,No_Of_Reg,Size_Of_Reg,Data_Size,Device_Size;
extern dev_t dev_id,dev_number;

void initialization(void);

struct Qset				// Items
{
	void **data;			//Quantum sets containing quantums
	struct Qset* next;
};

struct Dev
{
	struct cdev c_dev;		// Kernel data structure
	struct Qset *start;		// Pointer to Item
	int no_of_reg;
	int size_of_reg;
	int data_size;
	int device_size;
	struct semaphore sem;
};

extern struct Dev *dev; 

void wow_module(void);

int openDev(struct inode*, struct file*);
int releaseDev(struct inode*, struct file*);
ssize_t readDev(struct file*,char __user*,size_t,loff_t *);
ssize_t writeDev(struct file*,const char __user*,size_t,loff_t *);
loff_t lseekDev(struct file*,loff_t,int);
int clear_device(struct Dev*);

struct Qset* createScull(size_t);
