#include <stdio.h>
#include <stdio.h>
#include <dlfcn.h>
#include "libN.h"

int main()
{
	void* handle=dlopen("libN.so",RTLD_LAZY);
	lib1func();
	lib2func();
	lib3func();

	return 0;
}