#include"headers.h"
#include"proto.h"

int mainMenu()
{
	int choice;
	printf("~~~~~~~ MAIN MENU ~~~~~~~\n");
	printf("1. OPEN FILE\n");
	printf("2. READ FROM FILE\n");
	printf("3. WRITE TO FILE\n");
	printf("4. CLOSE FILE\n");
	printf("0. EXIT\n");
	scanf("%d",&choice);
	return choice;
}
