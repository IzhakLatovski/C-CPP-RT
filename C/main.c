#include <stdio.h>
#include <stdlib.h>
#include "working.h"

int main()
{
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
		switch(chosen)
		{
			case 1:
				printf("Choose a feature:\n");
				scanf("%d",&feature);
				bitOn(bitmap,feature);
				break;

			case 2:
				printf("Choose a feature:\n");
				scanf("%d",&feature);
				bitOff(bitmap,feature);
				break;

			case 3:
				printf("Choose a feature:\n");
				scanf("%d",&feature);
				printf("%d\n",bitStatus(bitmap,feature));
				break;

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