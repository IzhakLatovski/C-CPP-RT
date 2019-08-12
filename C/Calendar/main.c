#include <stdio.h>
#include <stdlib.h>
#include "ad.h"

int main()
{
	int chosen=0, capacity=0, created=0, found=0;
	float hour=0.0;
	Meeting_t* meeting;
	Calendar_t* calendar;

	while(chosen>=0 && chosen<=6)
	{
		printf("Welcome. Choose an option:\n\nPress 1 to create a diary\npress 2 to add a meeting\npress 3 to remove a meeting\npress 4 to find a meeting\npress 5 to print the diary\npress 6 to remove the diary\n\n");

		scanf("%d",&chosen);
		switch(chosen)
		{
			case 1:
				created=1;
				printf("Insert capacity\n");
				scanf("%d",&capacity);
				calendar=createAd(capacity);
				if(calendar==NULL)
				{
					return -1;
				}
				break;
			case 2:
				if(created!=1)
				{
					printf("Create a diary first\n");
					break;
				}
				printf("Insert meeting\n");
				meeting=createMeeting();
				insertAppointment(calendar,meeting);
				break;
			case 3:
				if(created!=1)
				{
					printf("Create a diary first\n");
					break;
				}
				printf("Insert hour of meeting to be removed\n");
				scanf("%f",&hour);
				if((removeAppointment(calendar,hour))!=1)
				{
					printf("No meeting to remove\n");
				}
				
				break;
			case 4:
				if(created!=1)
				{
					printf("Create a diary first\n");
					break;
				}
				printf("Insert hour of meeting to find\n");
				scanf("%f",&hour);
				found=findAppointment(calendar,hour);
				if(found==(-1))
				{
					printf("No meeting in that time\n");
				}
				else
				{
					printf("There is a meeting in that time:\n");
					printf("start:%f end:%f in room:%d\n", calendar->array[found]->start_time, calendar->array[found]->end_time, calendar->array[found]->room_number);
				}
				break;
			case 5:
				if(created!=1)
				{
					printf("Create a diary first\n");
					break;
				}
				printAd(calendar);
				break;
			case 6:
				if(created!=1)
				{
					printf("Create a diary first\n");
					break;
				}
				destroyAd(calendar);
				printf("Thank you for using\n");
				break;		
				
		}
	}

	return 0;
}