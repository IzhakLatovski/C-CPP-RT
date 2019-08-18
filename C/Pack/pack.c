#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pack.h"

static void intToBinary(char string);


int packString(char* string)
{
	int i=0, j=0, k=0, size=0;

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
	
	k=0;
	for(j=0 ; j<size ; j++)
	{
		string[j]=(string[k] | string[k+1]<<4);
		k+=2;
	}

	for(k=0 ; k<size ; k++)
	{
		intToBinary(string[k]);
	}

	return i;
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


int packStringUnion(char* string)
{
	un ourUnion;
	int size=0, i=0, j=0;

	size=strlen(string)/2;
	if(strlen(string)%2==1)
	{
		size++;
	}

	for(i=0 ; i<size ; i++)
	{
		ourUnion.lr.left=(string[j]-'a');
		ourUnion.lr.right=(string[j+1]-'a');
		j+=2;
		string[i]=ourUnion.c;
	}

	for(j=0 ; j<size ; j++)
	{
		intToBinary(string[j]);
	}

	return i;
}
