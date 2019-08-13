#include <stdio.h>
#include <stdlib.h>
#include "files.h"

int main()
{
	int chosen=0, capacity=0, room=0, i=0;
	float hour=0.0, start=0.0, end=0.0;
	Meeting_t* meeting;
	Meeting_t* found;
	Calendar_t* calendar;
	printf("Insert capacity\n");
				scanf("%d",&capacity);
				calendar=createAd(capacity);
				if(calendar==NULL)
				{
					return -1;
				}
	
/************************************************************/
	loadFromFile(calendar);
/************************************************************/


	while(chosen>=0 && chosen<=4)
	{
		printf("\n\npress 1 to add a meeting\npress 2 to remove a meeting\npress 3 to find a meeting\npress 4 to print the diary\n\n");

		scanf("%d",&chosen);
		switch(chosen)
		{
			case 1:
				printf("Insert meeting\n");
				scanf("%f %f %d",&start,&end,&room);
				meeting=createMeeting(start,end,room);
				insertAppointment(calendar,meeting);
				break;
			case 2:
				printf("Insert hour of meeting to be removed\n");
				scanf("%f",&hour);
				if((removeAppointment(calendar,hour))!=1)
				{
					printf("No meeting to remove\n");
				}
				
				break;
			case 3:
				printf("Insert hour of meeting to find\n");
				scanf("%f",&hour);
				found=findAppointment(calendar,hour);
				if(found==(NULL))
				{
					printf("No meeting in that time\n");
				}
				else
				{
					printf("There is a meeting in that time:\n");
					printf("start:%f end:%f in room:%d\n", found->start_time, found->end_time, found->room_number);
				}
				break;
			case 4:
				printAd(calendar);
				break;
		}
		
		
	}
/************************************************************/
	storeToFile(calendar);
/************************************************************/

	destroyAd(calendar);
	printf("Thank you for using\n");

	return 0;
}
