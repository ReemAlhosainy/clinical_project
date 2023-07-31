CC = gcc


all: a.out clean


a.out: main.o function_prg.o passfunc.o 
	gcc main.o function_prg.o passfunc.o -o a.out


main.o: main.c
	gcc -c main.c

function_prg.o: function_prg.c
	gcc -c function_prg.c

passfunc.o: passfunc.c
	gcc -c passfunc.c

clean:
		-rm *.o