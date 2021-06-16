#include"headers.h"
#include"proto.h"

int readDevice(void* mode)
{
	printf(">>>>>>>>>> %s Begins >>>>>>>>>>\n",__func__);
	if (strcmp(mode,"O_WRONLY")==0) {
		printf("%s: Please  open the file first in O_RDONLY mode\n",__func__);
		return -1;
	}
	char rbuff[40];
	int wret=read(fd,rbuff,40);
	if(wret == -1) {
		perror("read");
		exit(1);
	}
	rbuff[20]='\0';
	printf("%s: read ----> %s\n",__func__,rbuff);
	printf(">>>>>>>>>> %s Ends >>>>>>>>>>\n",__func__);
	return 0;
}
