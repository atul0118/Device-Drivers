#include"headers.h"
#include"declarations.h"

static int my_set(const char *val, const struct kernel_param *kp)
{
    int n = 0, ret;
    ret = kstrtoint(val,10,&n);														// Kernel function to convert string to integer
    if (ret !=0 || n > 10) {
        return -EINVAL;
    } 
	printk(KERN_ALERT "my-set function running\n");
    return param_set_int(val,kp);
}

static const struct kernel_param_ops param_ops = { 
    .set    = my_set,
    .get    = param_get_int,
};


module_param(num,int,S_IWUSR);
//module_param(num,int,0770);

static char *name = "Atul";
module_param(name,charp,0770);

static int __init init_func(void)
{
	int i;
	module_param_cb(callBack, &param_ops, &num, 0770);
	for( i=0; i<num; i++) 
	{
		printk(KERN_INFO "%s\n", name);
	}
	return 0;
}

static void __exit exit_func(void)
{
	printk(KERN_ALERT "Module removed successfully\n");

}


module_init(init_func);
module_exit(exit_func);
