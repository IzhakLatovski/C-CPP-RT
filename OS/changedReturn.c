#include <stdio.h>

int a(int x);
int b();

int main()
{	
	int number=0;
	printf("\n--MAIN BEGIN--\n");
	a(number);
	printf("--MAIN END--\n\n");
}

int a(int x)
{
	int result=x;

	int* address;
	printf("--INSIDE A--\n");
	address=&x;
	address-=1;
	*address=(int)b;

	printf("--FINISHED A--\n");
	return result;
}

int b()
{
	printf("-------BBBBBBBBBBBB----------\n\n");
	return 0;
}