#include <stdio.h>

unsigned int factorial(unsigned int n);

int main()
{
	unsigned int number=0;
	printf("Enter a number\n");
	scanf("%u",&number);
	printf("%u\n",factorial(number));

	return 0;
}

unsigned int factorial(unsigned int n)
{
	if(n==0 || n==1)
	{
		return 1;
	}
	else
	{
		return factorial(n-1)*n;
	}
}
