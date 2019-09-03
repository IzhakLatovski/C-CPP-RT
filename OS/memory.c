#include "memory.h"
#include <stdlib.h>

static void setFree(unsigned int* header);
static void setOccupied(unsigned int* header);
static int isFree(unsigned int* header);

static void setFree(unsigned int* header)
{
	*header=*header & 0x7fffffff;
}

static void setOccupied(unsigned int* header)
{
	*header=*header | 0x80000000;
}

static int isFree(unsigned int* header)
{
	int result=(((*header) & 0x80000000)==1 ? 1 : 0);

	return result;
}

static char* split(int* header, int size)
{
	*header=size+4;
	*(header+(size/4)+1)=*header-size+4;
	*header=size+4;
	setOccupied(header);
	setFree(header+(size/4)+1);

	return (char*)header+1;
}

/**********************************************************/

void* memInit(char* buffer, int* sizeBuffer)
{
	int* header;
	unsigned int temp=((unsigned int)buffer%4);

	if(temp!=0)
	{
		(*sizeBuffer)=(*sizeBuffer)-(4-temp);
		buffer=buffer+(4-temp);
	}
	if(((unsigned int)buffer+(*sizeBuffer)-1)%4!=0)
	{
		(*sizeBuffer)=(*sizeBuffer)-(((unsigned int)buffer+(*sizeBuffer)-1)%4);
	}
	header=(int*)&buffer[0];
	*header=*sizeBuffer;
	setFree(header);

	return;
}

void* memAlloc(char* buffer,  int sizeBuffer, int sizeAlloc )
{   
	char i=0;
    int* header;

    if(sizeAlloc%4!=0)
    {
        sizeAlloc=sizeAlloc+(4-sizeAlloc%4);
    }
    while(i<sizeBuffer)
    {   
    	header=(int*)&buffer[i];
        if(isFree(header)==0)
        {
            if(sizeAlloc+4<*header)
            {
                return split(header,sizeAlloc);

            }
            if(sizeAlloc=*header-4)
            {
                return header+1;
            }
            else if(sizeAlloc+4<*header)
            {
                i=i+(*header/4);
            }

        }
        else 
        {
             i=i+(*header/4);    
        }
    }
    return NULL;
}

void memFree(char* pointer,int sizeBuffer)
{
    char i=0;
    char* header=pointer;
    int current=*((int*)header);

    setFree((int*)pointer);
    while(current<=sizeBuffer && isFree((int*)(header+*header))==0)
    {
        *pointer+=*(header+*header);
        header+=*header;
        current=current+(*((int*)header));
    }

    return;
}
