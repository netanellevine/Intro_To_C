CC=gcc
FLAGS = -Wall -g


#make all
all: stringProg library

#make stringProg
stringProg: main.o stringlib.h lib.a
	$(CC) $(FLAGS) -o stringProg main.o lib.a

library: lib.a

main.o: main.c stringlib.h
	$(CC) $(FLAGS) -c main.c

stringlib.o: stringlib.c
	$(CC) $(FLAGS) -c stringlib.c

lib.a: stringlib.o
	ar -rcs lib.a stringlib.o

.PHONY: clean all
#make clean
clean:
	rm -f *.o *.a stringProg
