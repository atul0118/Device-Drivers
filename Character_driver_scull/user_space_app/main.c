#include"headers.h"
#include"proto.h"
int fd=-1;

int main()
{
	int choice;
	char *mode;
	mode=(char*)malloc(sizeof(char)*8);
	init();
	int (*arr[4])(void*);
	arr[0]=opde;
	arr[1]=clde;
	arr[2]=rede;
	arr[3]=wrde;
	while(1) {
		choice=mainMenu();
		if(choice==1) {							// Opening the file
			printf("O_RDONLY or O_WRONLY mode???\n");
			scanf("%s",mode);
			fd = (*arr[0])(mode);
			printf("fd = %d\n",fd);
		}

		if(choice==4) {							// Closing the file
			(*arr[1])((void*)fd);
			fd=-1;
		}
		if(choice==3) {							// Write to file
			(*arr[3])(mode);
		}
		if(choice==0) {							// Exit
			exit(0);
		}
		if(choice==2) {							// Read to file
			(*arr[2])(mode);
		}
	}
	return 0;

}
