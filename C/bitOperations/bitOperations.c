#include <stdio.h>
#include <stdlib.h>
#include "bitOperations.h"

static void intToBinary(int number);


int invert(unsigned char x)
{
	unsigned char y;

	y=x^255;

	printf("x = ");
	intToBinary(x);
	printf(" (binary)\n");
	printf("x inverted = ");
	intToBinary(y);
	printf(" (binary)\n");

	return 0;
}


int rotate(unsigned char x, unsigned int n)
{
	unsigned char temp=x, toPrint=x;

	temp=temp<<(8-(num%8));
	x=x>>(num%8);
	x=x|temp;

	printf("x = ");
	intToBinary(toPrint);
	printf(" (binary)\n");
	printf("x rotated by %u = ",n);
	intToBinary(x);
	printf(" (binary)\n");

	return 0;
}

unsigned int setbits(unsigned char x, unsigned int p, unsigned int n, unsigned char y)
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





/*function to print*/
static void intToBinary(int number)
{
  int i=0, temp=0;
   
  for (i=0; i<sizeof(unsigned char)*8 ; i++)
  {
    temp=number>>i;
 
    if (temp&1)
      printf("1");
    else
      printf("0");
  }
 
  return;
}
