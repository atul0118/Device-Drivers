#include"headers.h"
#include"proto.h"

int closeDevice(void* fd)
{
	if ( fd == -1 )
	{
		printf("%s: Open the file first\n",__func__);
		return -1;
	}
	printf("%s: Begins\n",__func__);
	int *i;
	i=(int*)fd;
	printf("%d\n",i);
	close(i);
	printf("%s: Ends\n",__func__);
	return 0;
}
