#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/slab.h>
#include<linux/uaccess.h>
#include<linux/moduleparam.h>
#include<linux/semaphore.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("ATUL");
MODULE_DESCRIPTION("Demo of character device driver");
