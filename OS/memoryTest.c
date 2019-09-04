#include "memory.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE 16

void print(unsigned int* buffer, unsigned int isFreeFlag);

unsigned int buffer [32];

int main()
{   
	unsigned int size=SIZE;
	unsigned int request=0, isFreeFlag=1;

  	memInit(buffer,&size);

  	print(buffer,isFreeFlag);

  	printf("\nEnter the required size\n");
  	scanf("%u",&request);

  	memAlloc(buffer,20,request);

	if(isOccupied(buffer)==1)
	{
		isFreeFlag=0;
	}

  	print(buffer,isFreeFlag);

	return 0;
}

void print(unsigned int* buffer, unsigned int isFreeFlag)
{
	unsigned int i=0;
	if(isFreeFlag)
	{
		printf("_%d_| ",getSize(buffer));
	}
	else
	{
		printf("@%d@| ",getSize(buffer));
	}
  	for(i=1 ; i<SIZE+1 ; i++)
  	{
  		printf("%u",buffer[i]);
  	}
}