CC = gcc
CFLAGS = -Wall -Wextra -Werror

rush-02: main.o convert.o ext_convert.o memory.o extra.o ext_extra.o
	gcc -o rush-02 main.o convert.o ext_convert.o memory.o extra.o ext_extra.o

main.o: rush.h main.c
	gcc -c -o main.o main.c

convert.o: rush.h convert.c
	gcc -c -o convert.o convert.c

ext_convert.o: rush.h ext_convert.c
	gcc -c -o ext_convert.o ext_convert.c

memory.o: rush.h memory.c
	gcc -c -o memory.o memory.c

extra.o: rush.h extra.c
	gcc -c -o extra.o extra.c

ext_extra.o: rush.h ext_extra.c
	gcc -c -o ext_extra.o ext_extra.c

clean:
	rm *.o rush-02
