#include"headers.h"
#include"declarations.h"

static int my_set(const char *val, const struct kernel_param *kp)
{
	int n = 0, ret;
	ret = kstrtoint(val,10,&n);
	if (ret !=0 || n > 10) {
		return -EINVAL;
	}

	return param_set_int(val,kp);

}


static const struct kernel_param_ops param_ops = {
	.set	= my_set,
	.get	= param_get_int,
};

module_param_cb(simpcb, &param_ops, &num, 0664);
