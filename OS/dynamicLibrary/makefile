CFLAGS = -ansi -pedantic

doall: lib1.o lib2.o lib3.o libN.so progA.o progB.o prog

lib1.o : lib1.c libN.h
	gcc -c ${CFLAGS} -fPIC lib1.c

lib2.o : lib2.c libN.h
	gcc -c ${CFLAGS} -fPIC lib2.c

lib3.o : lib3.c libN.h
	gcc -c ${CFLAGS} -fPIC lib3.c

libN.so : lib1.o lib3.o lib3.o
	gcc -o libN.so -shared lib1.o lib2.o lib3.o

progA.o : progA.c progB.h
	gcc -c ${CFLAGS} progA.c

progB.o : progB.c progB
	gcc -c ${CFLAGS} progB.c

prog : progA.o progB.o libN.so
	gcc -o prog progA.o progB.o -lN -L. 