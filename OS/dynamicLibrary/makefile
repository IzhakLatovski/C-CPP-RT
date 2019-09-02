CFLAGS = -ansi -pedantic

doall: lib1.o lib2.o lib3.o libN.so progA.o progB.o prog

lib1.o : lib1.c 
	gcc -c ${CFLAGS} -fPIC lib1.c

lib2.o : lib2.c 
	gcc -c ${CFLAGS} -fPIC lib2.c

lib3.o : lib3.c 
	gcc -c ${CFLAGS} -fPIC lib3.c

libN.so : lib1.o lib3.o lib3.o
	gcc -o libN.so -shared lib1.o lib2.o lib3.o

progA.o : progA.c 
	gcc -c ${CFLAGS} progA.c

progB.o : progB.c 
	gcc -c ${CFLAGS} progB.c

prog : progA.o progB.o libN.so
	gcc -o prog progA.o progB.o -lN -L. 