CFLAGS = -g

aprog : darray_testing.o darray_int.o
	gcc -o executable darray_testing.o darray_int.o

darray_testing.o : darray_testing.c darray_int.h
	gcc -c $(CFLAGS) darray_testing.c

darray_int.o : darray_int.c darray_int.h
	gcc -c $(CFLAGS) darray_int.c
