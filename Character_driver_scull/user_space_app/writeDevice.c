#include"headers.h"
#include"proto.h"

int writeDevice(void* mode)
{
	printf(">>>>>>>>>> %s Begins >>>>>>>>>>\n",__func__);
	if (mode == NULL) {
		printf("%s: Please  open the file first in O_WRONLY mode\n",__func__);
		return -1;
	}
	char wbuff[]="Tough day :(";
	int wret=write(fd,wbuff,strlen(wbuff));
	if(wret == -1) {
		perror("write");
		exit(1);
	}
	printf(">>>>>>>>>> %s Ends >>>>>>>>>>\n",__func__);
	return 0;
}
