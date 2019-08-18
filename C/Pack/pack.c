#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pack.h"

static void intToBinary(char string);


int packString(char* string)
{
	int i=0, j=0, size=0;

	size=strlen(string)/2;
	if(strlen(string)%2==1)
	{
		size++;
	}
	
	while(string[i]!='\0')
	{
		string[i]-='a';
		i++;
	}
	
	i=0;
	for(j=0 ; j<size ; j++)
	{
		string[j]=(string[i] | string[i+1]<<4);
		i+=2;
	}

	for(i=0 ; i<size ; i++)
	{
		intToBinary(string[i]);
	}

	return strlen(string);
}


static void intToBinary(char string)
{
	int i=0, temp=0;
	   
	for (i=0; i<sizeof(char)*8 ; i++)
	{
	 	temp=string>>i;
	    if (temp&1)
	    {
	        printf("1");
	    }
	    else
	    {
	        printf("0");
	    }
	}
	printf("---");

    return;
}
