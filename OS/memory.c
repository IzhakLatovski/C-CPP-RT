#include "memory.h"
#include <stdlib.h>
#include <stdio.h>

static void setFree(unsigned int* header);
static void setOccupied(unsigned int* header);

static void setFree(unsigned int* header)
{
	*header=*header & 0x7fffffff;
}

static void setOccupied(unsigned int* header)
{
	*header=*header | 0x80000000;
}

int isOccupied(unsigned int* header)
{
	int result=(((*header) & 0x80000000)==1 ? 1 : 0);

	return result;
}

unsigned int getSize(unsigned int* header)
{
	unsigned int* temp;
	*temp=*header & 0x7fffffff;

	return(*header);
}

/*
static char* split(int* header, int size)
{
	*header=size+4;
	*(header+(size/4)+1)=*header-size+4;
	*header=size+4;
	setOccupied(header);
	setFree(header+(size/4)+1);

	return (char*)header+1;
}
*/
/**********************************************************/

void* memInit(unsigned int* buffer, unsigned int* sizeBuffer)
{
	unsigned int* header;

	header=&buffer[0];
	*header=*sizeBuffer+1;
	setFree(header);

	return;
}

void* memAlloc(unsigned int* buffer,  unsigned int sizeBuffer, unsigned int sizeAlloc)
{
	unsigned int* header;
	unsigned int temp=0;

	if(sizeAlloc<=0)
	{
		printf("small alloc size\n");

		return NULL;
	}

	if(isOccupied(buffer)==0) /*if first is free*/
	{
		if(sizeAlloc+1<=(*buffer)) /*if enough size*/
		{
			header=&buffer[sizeAlloc+1];
			*header=buffer[0]-(sizeAlloc+1);
			setFree(header);

			header=&buffer[0];
			*header=sizeAlloc+1;
			setOccupied(header);
		}
		else
		{
			printf("bad 1\n");
		}
	}
	else
	{
		temp=getSize(buffer);
		setOccupied(buffer);
		memAlloc(buffer+temp,sizeBuffer,sizeAlloc);
	}

	return;
}