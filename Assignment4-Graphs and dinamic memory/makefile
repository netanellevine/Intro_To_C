CC=gcc
FLAGS= -Wall -g

all: graph

graph: main.o MyGraph.o MyQueue.o lib_MyGraph.a
		$(CC) $(FLAGS) -o graph main.o -L . -l_MyGraph

main.o: main.c
		$(CC) $(FLAGS) -c main.c

lib_MyGraph.a: MyGraph.o MyQueue.o
		ar rcs lib_MyGraph.a MyGraph.o MyQueue.o

MyGraph.o: MyGraph.c
		$(CC) $(FLAGS) -c MyGraph.c

MyQueue.o: MyQueue.c
		$(CC) $(FLAGS) -c MyQueue.c


.PHONY: clean all
#make clean

clean:
	rm -f *.o *.a graph
