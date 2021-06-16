#include"headers.h"
#include"proto.h"

int openDevice(void* dmode)
{
	int dfd;
	printf("%s Begin\n",__func__);
	if(strncmp(dmode,"O_WRONLY",8)==0) {
		dfd = open("my_file",O_WRONLY);
		if(dfd == -1) {
			perror("open");
			exit(1);
		}
		printf("File opened in O_WRONLY mode\n");
	}
	else if(strncmp(dmode,"O_RDONLY",8)==0) {
		dfd = open("my_file",O_RDONLY);
		if(dfd == -1) {
			perror("open");
			exit(1);
		}
		printf("File opened in O_RDONLY mode\n");
	}
	else {
		printf("%s  Please Enter correct mode\n",__func__);
		return -1;
	}
	printf("%s End\n",__func__);
	return dfd;
}
