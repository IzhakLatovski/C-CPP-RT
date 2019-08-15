#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int numberOfFeatures_m;
	int* array_m;
} bitmap_t;

/*-----------------------------------------------------*/
typedef int (*binFunction)(bitmap_t* bitmap, int feature);
typedef enum {
	bitOn,
	bitOff,
	bitStatus
} functions;


bitmap_t* createBitmap(int nf)
{
	int i=0;

	bitmap_t* bitmap;
	bitmap=(bitmap_t*)malloc(sizeof(bitmap_t));
	if(bitmap==NULL)
	{
		return NULL;
	}
	bitmap->array_m=(int*)malloc((sizeof(int)*(nf/32)));
	if (bitmap->array_m==NULL)
	{
			free(bitmap);
			return NULL;
	}
	bitmap->numberOfFeatures_m=nf;
	for(i=0 ; i<(nf/32)+1 ; i++)
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
		return 0;
	}
	else
	{
		return 1;
	}
	/*shift, and*/
}

int main()
{
	binFunction func;
	bitmap_t* bitmap;
	int numberOfFeatures=0, chosen=0, feature=0;;

	printf("Insert total number of features\n");
	scanf("%d",&numberOfFeatures);
	bitmap=createBitmap(numberOfFeatures);
	if(bitmap==NULL)
	{
		return -1;
	}

	while(1)
	{
		printf("Choose an option:\n");
		printf("1. Turn on a feature\n");
		printf("2. Turn off a feature\n");
		printf("3. Get status of a feature\n");
		printf("4. Print all features\n");
		printf("Other number - Exit\n");

		scanf("%d",&chosen);

		if(chosen>=1 && chosen<=3)
		{
			printf("Choose a feature:\n");
			scanf("%d",&feature);
			func=&functions[chosen-1];
			*func(bitmap,feature);
		}

		switch(chosen)
		{
			
			case 4:
				printAllFeatures(bitmap);
				break;

			default:
				destroyBitmap(bitmap);
				return 0;
		}
	}

	destroyBitmap(bitmap);

	return 0;
}