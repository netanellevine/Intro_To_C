CC=gcc
FLAGS= -Wall -g

#make all
all: connections library

#make connections
connections: main.o my_mat.h lib.a
	$(CC) $(FLAGS) -o connections main.o lib.a

library: lib.a

main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c

my_mat.o: my_mat.c
	$(CC) $(FLAGS) -c my_mat.c

lib.a: my_mat.o
	ar -rcs lib.a my_mat.o

.PHONY: clean all
#make clean
clean:
	rm -f *.o *.a *.so