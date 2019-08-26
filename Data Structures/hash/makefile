CFLAGS = -g

aprog : hash.o hashTest.o
	gcc -o executable hash.o hashTest.o

hash.o : hash.c hash.h
	gcc -c $(CFLAGS) hash.c

hashTest.o : hashTest.c hash.h
	gcc -c $(CFLAGS) hashTest.c