CC=gcc
AR=ar
RECURSION = basicClassification.o advancedClassificationRecursion.o
LOOP = basicClassification.o advancedClassificationLoop.o
FLAGS= -Wall -g


all: loopd loops recursived recursives maindloop maindrec mains

loops: libclassloops.a
loopd: libclassloops.so
recursives: libclassrec.a
recursived: libclassrec.so


mains: main.o libclassrec.a
	$(CC) $(CFLAGS) -o mains main.o libclassrec.a -lm

maindloop: main.o libclassloops.so
	$(CC) $(CFLAGS) -o maindloop main.o ./libclassloops.so -lm

maindrec: main.o libclassrec.so
	$(CC) $(CFLAGS) -o maindrec main.o ./libclassrec.so -lm

libclassrec.a: $(RECURSION)
	$(AR) -rcs libclassrec.a $(RECURSION)

libclassrec.so: $(RECURSION)
	$(CC) -shared  $(RECURSION) -o libclassrec.so

libclassloops.a: $(LOOP)
	$(AR) -rcs libclassloops.a $(LOOP)

libclassloops.so: $(LOOP)
		$(CC) -shared  $(LOOP) -o libclassloops.so

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c

.PHONY: clean loops loopd reccursived reccursives
#make clean
clean:
	rm -f *.o *.a *.so maindloop maindrec mains