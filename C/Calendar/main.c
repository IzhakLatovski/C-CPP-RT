#include <stdio.h>
#include <stdlib.h>
#include "ad.h"

int main()
{
	int chosen=0, capacity=0;
	float hour=0.0;
	Meeting_t* meeting;
	Calendar_t* calendar;

	while(chosen>=0 && chosen<6)
	{
		printf("Welcome. Choose an option:\n\nPress 1 to create a diary\npress 2 to add a meeting\npress 3 to remove a meeting\npress 4 to find a meeting\npress 5 to print the diary\npress 6 to remove the diary\n\n");

		scanf("%d",&chosen);
		switch(chosen)
		{
			case 1:
				printf("Insert capacity\n");
				scanf("%d",&capacity);
				calendar=createAd(capacity);
				if(calendar==NULL)
				{
					return -1;
				}
				break;
			case 2:
				printf("Insert meeting\n");
				meeting=createMeeting();
				insertAppointment(calendar,meeting);
				break;
			case 3:
				printf("Insert hour of meeting to be removed\n");
				scanf("%f",&hour);
				if((removeAppointment(calendar,hour))!=1)
                                {
                                     printf("no meeting to remove");
                                }
				break;
			case 4:

				break;
			case 5:
				printAd(calendar);
				break;
			case 6:
				destroyAd(calendar);
				printf("Thank you for using\n");			
				return 0;
		}
	}

	return 0;
}

/* 

Testing

1. Hours >= 0
2. Hours <24
3. Room number > 0

4. End > start
5. If start before other start - end before other start
6. If start after another and before end - wrong

7. If not such hour remove
8. If no such hour find

*/
