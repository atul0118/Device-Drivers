int openDevice(void*);
int (*opde)(void*);
int closeDevice(void*);
int (*clde)(void*);
int readDevice(void*);
int (*rede)(void*);
int writeDevice(void*);
int (*wrde)(void*);

int mainMenu();
int init();

extern int fd;
