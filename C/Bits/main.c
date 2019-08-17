#include <stdio.h>
#include <stdlib.h>
#include "bits.h"

int main()
{
	bitmap_t* bitmap;
	int numberOfFeatures=0, chosen=0, feature=0;
	BitFunction functions[3]={bitOn,bitOff,bitStatus};

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
		
		if(chosen>0 && chosen<=3)
		{
			printf("Choose a feature:\n");
			scanf("%d",&feature);
			runFunction(functions[chosen-1],bitmap,feature);
		}
		else if(chosen==4)
		{

			printAllFeatures(bitmap);
		}
		else
		{
			destroyBitmap(bitmap);
			return 0;
		}
	}

	destroyBitmap(bitmap);

	return 0;
}