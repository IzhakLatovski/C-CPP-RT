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

	if(((unsigned int)buffer%4)!=0)	/* begin */
    {
        *sizeBuffer-=(4-((unsigned int)buffer%4));
        buffer+=(4-(unsigned int)buffer%4);
        
    }
    if(((unsigned int)buffer+(*sizeBuffer)-1)%4!=0)	/* end */
    {
        (*sizeBuffer)-=(((unsigned int)buffer+(*sizeBuffer)-1)%4);
    }

	header=&buffer[0];
	*header=*sizeBuffer+1;
	setFree(header);

	return;
}

void* memAlloc(unsigned int* buffer,  unsigned int sizeBuffer, unsigned int sizeAlloc)
{
	unsigned int* header, *a;
	unsigned int temp=0, index=0;

	if(sizeAlloc<=0)
	{
		printf("small alloc size\n");

		return NULL;
	}
	if(sizeAlloc%4!=0)
	{
        sizeAlloc+=(4-sizeAlloc%4);
	}

	while(index<sizeBuffer)
	{
		a=&buffer[index];
		if(isOccupied(a)==0) /*if first is free*/
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
			else if(sizeAlloc+1==(*a))
            {
                return a+1;
            }
			else
			{
				printf("bad 1\n");
				index+=(*a);
			}
		}
		else
		{
			temp=getSize(buffer);
			setOccupied(buffer);
			memAlloc(buffer+temp,sizeBuffer,sizeAlloc);
		}
	}

	return NULL;
}

void memFree(unsigned int* buffer, unsigned int* pointer, unsigned int sizeBuffer)
{
    unsigned int current=0, i=0;
    unsigned int* p=pointer;
   
    current=*(p-1);
    for(i=0 ; i<sizeBuffer ; i++)
    {
       if(buffer[i]==*(pointer))
       {
           break;
       }
    }
    i-=1;
    setFree(&(buffer[(char)i]));
    while((current<=sizeBuffer) && (isOccupied(p+*p)==1))
    {
        *pointer=*pointer+*(p+*p);
        p=p+*p;
        current+=(*p);
    }

    return;
}