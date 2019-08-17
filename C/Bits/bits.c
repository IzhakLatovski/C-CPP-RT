#include <stdio.h>
#include <stdlib.h>
#include "bits.h"


int runFunction(BitFunction function,bitmap_t* bitmap,int feature)
{
	return function(bitmap,feature); 
}





bitmap_t* createBitmap(int numberOfFeatures)
{
	int i=0;
	bitmap_t* bitmap;
	bitmap=(bitmap_t*)malloc(sizeof(bitmap_t));

	if(bitmap==NULL)
	{
		return NULL;
	}
	bitmap->array_m=(int*)malloc((sizeof(int)*(numberOfFeatures/32)));
	if (bitmap->array_m==NULL)
	{
			free(bitmap);
			return NULL;
	}
	bitmap->numberOfFeatures_m=numberOfFeatures;
	for(i=0 ; i<(numberOfFeatures/32)+1 ; i++)
	{
		bitmap->array_m[i]=0;
	}

	return bitmap;
}

void destroyBitmap(bitmap_t* bitmap)
{
	int i=0;

	if(bitmap==NULL)
	{
		return;
	}
	free(bitmap->array_m);
	free(bitmap);

	return;
}

void intToBinary(int n)
{
  int c=0, k=0;
   
  for (c=0; c<sizeof(int)*8 ; c++)
  {
    k=n>>c;
 
    if (k&1)
      printf("1");
    else
      printf("0");
  }
 
  return;
}


void printAllFeatures(bitmap_t* bitmap)
{
	int i=0;
	for(i=0 ; i<(bitmap->numberOfFeatures_m/32)+1 ; i++)
	{
		intToBinary(bitmap->array_m[i]);
	}
	printf("\n");
}



int bitOn(bitmap_t* bitmap, int feature)
{
	int block=0, index=0;

	if(feature<=0 || feature>bitmap->numberOfFeatures_m)
	{
		return -1;
	}
	block=(feature-1)/(sizeof(int)*8);
	index=(feature-1)%(sizeof(int)*8);
	bitmap->array_m[block]=(bitmap->array_m[block])|(1<<(index));

	return 1;
	/*shift, or*/
}

int bitOff(bitmap_t* bitmap, int feature)
{
	int block=0, index=0;

	if(feature<=0 || feature>bitmap->numberOfFeatures_m)
	{
		return -1;
	}
	block=(feature-1)/(sizeof(int)*8);
	index=(feature-1)%(sizeof(int)*8);
	bitmap->array_m[block]=(bitmap->array_m[block])&(~(1<<(index)));

	return 1;
	/*shift, not, and*/
}

int bitStatus(bitmap_t* bitmap, int feature)
{
	int block=0, index=0;

	if(feature<=0 || feature>bitmap->numberOfFeatures_m)
	{
		return -1;
	}
	block=(feature-1)/(sizeof(int)*8);
	index=(feature-1)%(sizeof(int)*8);
	if(((bitmap->array_m[block])&(1<<(index)))==0)
	{
		printf("Bit status is 0\n");	/*JUST TO CHECK*/
		return 0;
	}
	else
	{
		printf("Bit status is 1\n");	/*JUST TO CHECK*/
		return 1;
	}
	/*shift, and*/
}