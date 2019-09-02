#include <stdio.h>
#include "progB.h"
#include "libN.h"

void progAfunc()
{
	printf("this is A\n");
	return;
}

int main()
{
	progAfunc();
	progBfunc();
	lib1func();
	lib2func();
	lib3func();

	return 0;
}