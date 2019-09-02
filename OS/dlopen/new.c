#include <stdio.h>
#include <stdio.h>
#include <dlfcn.h>
#include "libN.h"

int main()
{
	void (*runLib)(void);
        char function[64];
	void* handle=dlopen("libN.so",RTLD_LAZY);

	printf("Enter library:\n");
        scanf("%s",function);
	*(void **)(&runLib) = dlsym(handle, func);
	runLib();
	lib1func();
	lib2func();
	lib3func();
	dlclose(handle);

	return 0;
}
