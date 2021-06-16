app: main.o mainMenu.o init.o openDevice.o closeDevice.o readDevice.o writeDevice.o
	gcc -o app main.o mainMenu.o init.o openDevice.o closeDevice.o readDevice.o writeDevice.o

main.o: main.c headers.h proto.h
	gcc -c main.c

mainMenu.o: mainMenu.c headers.h proto.h
	gcc -c mainMenu.c

init.o: init.c headers.h proto.h
	gcc -c init.c

openDevice.o: openDevice.c headers.h proto.h
	gcc -c openDevice.c
closeDevice.o:closeDevice.c headers.h proto.h
	gcc -c closeDevice.c
readDevice.o: readDevice.c headers.h proto.h
	gcc -c readDevice.c
writeDevice.o: writeDevice.c headers.h proto.h
	gcc -c writeDevice.c
