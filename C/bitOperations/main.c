#include <stdio.h>
#include "bitOperations.h"


int main()
{
	unsigned char x=86;
	invert(x);

	setbitsTwo(0,3,5,1);

	return 0;
}

int setbits(unsigned char x, unsigned int p, unsigned int n, unsigned char y)
{
	unsigned char temp=x;

	temp=temp>>p;
	temp=temp<<p;
	x=x<<(8-p+n);
	x=x>>(8-p+n);
	y=y<<(8-n);
	y=y>>(8-p);
	x=(x|temp);
	x=x|y;

	return x;
}