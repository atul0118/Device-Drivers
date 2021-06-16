#include"headers.h"
#include"proto.h"

int init()
{
	opde=openDevice;
	clde=closeDevice;
	rede=readDevice;
	wrde=writeDevice;
	return 0;
}
