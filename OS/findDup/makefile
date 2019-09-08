CFLAGS= -pedantic -ansi -g
CC = gcc

doall: finddup.o hash.o md5m.o init.o fileOps.o

filecheck : finddup.o hash.o md5m.o init.o
	$(CC) -o filecheck finddup.o hash.o md5m.o init.o -lcrypto -lssl

finddup.o : finddup.c finddup.h md5m.h init.h hash.h
	$(CC)  -c $(CFLAGS) finddup.c -lstat

init.o : init.c init.h hash.h
	$(CC)  -c $(CFLAGS) init.c

md5m.o : md5.c md5.h
	$(CC) -c $(CFLAGS) md5m.c -lcrypto -lssl

hash.o : hash.c hash.h
	$(CC)  -c $(CFLAGS) hash.c

fileOps.o : fileOps.c fileOps.h
	$(CC)  -c $(CFLAGS) fileOps.c
