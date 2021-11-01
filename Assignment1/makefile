CC=gcc
AR=ar
#OBJECTS_MAIN=main.o
#OBJECTS_LIB=NumClass.o
FLAGS= -Wall -g


#make loops
loops: libclassloops.a
libclassloops.a: NumClass.o
	$(AR) -rcs libclassloops.a NumClass.o

#make loopd
loopd: libclassloops.so
libclassloops.so: NumClass.o
	$(CC) -shared -o libclassloops.so NumClass.o

#make recursives
loops: libclassrec.a
libclassrec.a: NumClass.o
	$(AR) -rcs libclassrec.a NumClass.o

#make recursived
loopd: libclassrec.so
libclassrec.so: NumClass.o
	$(CC) -shared -o libclassrec.so NumClass.o
NumClass.o: basicClassification.c advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c advancedClassificationLoop.c
#make recursives
#make recursived
#make mains
#make maindloop
#make maindrec
#make all
.PHONY: clean loops
#make clean
clean:
	rm -f *.o *.a *.so