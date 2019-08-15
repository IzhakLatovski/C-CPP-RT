#include <stdio.h>
#include <stdlib.h>
#include "dates.h"

int main()
{
	int hour=0, minute=0, second=0, format=0;
	int chosen=0, chooseObject=0;
	cTime_t* new;

	



	cTime_t* firstObject;
	cTime_t* secondObject;


	firstObject=(cTime_t*)malloc(sizeof(cTime_t));
	if(firstObject==NULL)
	{
		return -1;
	}

	secondObject=(cTime_t*)malloc(sizeof(cTime_t));
	if(secondObject==NULL)
	{
		return -1;
	}
	





	while(chosen>=0 && chosen<=3)
	{
		printf("Enter your selection\n");
		printf("1. Set new time\n");
		printf("2. Print the object\n");
		printf("3. Add the 2 times you have set in option 1\n");


		scanf("%d",&chosen);

		switch(chosen)
		{
			case 1:
				printf("Set first or second object?\n");
				scanf("%d",&chooseObject);
				printf("Enter your hour\n");
				scanf("%d",&hour);
				printf("Enter your minute\n");
				scanf("%d",&minute);
				printf("Enter your second\n");
				scanf("%d",&second);
				if(chooseObject==1)
				{
					setNewTime(firstObject,hour,minute,second);

				}
				else
				{
					setNewTime(secondObject,hour,minute,second);

				}
				break;

			case 2:
				printf("Enter your desired format\n");
				scanf("%d",&format);
				printTime(new,format);
				break;

			case 3:
				addTimes(firstObject,secondObject);
				printf("result:\n");
				printTime(firstObject,1);
				break;
		}

	}
	




	free(firstObject);
	free(secondObject);

	return 0;
}
