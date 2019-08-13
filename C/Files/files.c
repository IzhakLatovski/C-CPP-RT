#include <stdio.h>
#include <stdlib.h>
#include "files.h"



Calendar_t* createAd(int size)	/* create calendar */
{
    Calendar_t* calendar;
    calendar=(Calendar_t*)malloc(sizeof(Calendar_t));
    if(calendar==NULL)
    {
        return NULL;
    }
    (calendar->array)=(Meeting_t**)malloc((sizeof(Meeting_t*))*size);
    if(calendar->array==NULL)
    {
        free(calendar);
        return NULL;
    }
    calendar->capacity=size;
    calendar->index=0;
    
    return calendar;
}


Meeting_t* createMeeting(float a, float b, int room) /* create a meeting */
{
    float start=0,end=0;
    Meeting_t* meeting;
    meeting=(Meeting_t*)malloc(sizeof(Meeting_t));
    if(meeting==NULL)
    {
	return NULL;
    }
	start=a;
	while(start<0 || start>=24)
	{
		printf("Enter legal time\n");	
		scanf("%f",&start);
	}
	end=b;
	while(end<0 || end>=24)
	{
		printf("Enter legal time\n");	
		scanf("%f",&end);
	}
	while(room <1)
	{
		printf("Enter legal room number\n");	
		scanf("%d",&room);
	}
	if(start>=end)	/* start must be before end */
	{
		printf("Meeting can't end before it started\n");
		return NULL;
	}
	meeting->start_time=start;
	meeting->end_time=end;
	meeting->room_number=room;

    return meeting;
}


void destroyAd(Calendar_t* calendar)	/* free all the memories and return */
{
    int i=0;
    if(calendar==NULL)
    {
        return;
    }
    for(i=0 ; i<(calendar->index) ; i++)
    {
        free(calendar->array[i]);
    }
    free(calendar->array);
    free(calendar);
    
    return;
    
}


void printAd(Calendar_t* calendar)	/* print every meeting in a row */
{
    int i=0;
    if(calendar!=NULL)
    {
        for(i=0 ; i<(calendar->index) ; i++)
        {
            printf("start:%f end:%f in room:%d\n", calendar->array[i]->start_time, calendar->array[i]->end_time, calendar->array[i]->room_number);
        }
    }
    
    return;
}



int insertAppointment(Calendar_t* calendar, Meeting_t* meeting)
{
	Meeting_t* temp;
	int i=0, j=0, place=0;
	if(calendar==NULL || meeting==NULL)
	{
		return 0;
	}
	if(calendar->array==NULL)
	{
		return 0;
	}
	if(calendar->index==0) /* if calendar is empty,insert */
	{
		calendar->array[0]=meeting;
		calendar->index++;
		return 1;
	}

/* --------------------find the right place for inserting (if no place return 0)------------------------- */

	if(meeting->end_time<=calendar->array[0]->start_time) /* first */
	{
		place=0;
	}
	else if(meeting->start_time>=calendar->array[calendar->index-1]->end_time) /* last */
	{
		place=calendar->index;
	}
	else /* not first or last or only one */
	{
		for(i=0 ; i<calendar->index ; i++) /* compare with every meeting */
		{
			if((meeting->start_time)>(calendar->array[i]->end_time)) /* start checking if not overlaps with previous */
			{
				if(i+1==calendar->index) 
				{
					place++;
					break;	
				}
				else if((calendar->array[i+1]->start_time)>meeting->start_time)
				{
					if((calendar->array[i+1]->start_time)>(meeting->end_time)) /* if the next one starts after this one ends-good */
					{
						place++;
						break;
					}
					else if((calendar->array[i+1]->start_time)<(meeting->end_time)) /* overlap */
					{
						return 0;
					}	
				}					
			}
		}
		if(i==calendar->index) /* if we got here, no legal place for meeting */
		{
			return 0;
		}
	}

	if ((calendar->index)==(calendar->capacity)) /* need more space */
	{
		temp=*calendar->array;
		calendar->array=realloc(calendar->array,(calendar->capacity)*2*sizeof(meeting));
		if (calendar->array)
		{
			calendar->capacity*=2;
		}
		else{
			calendar->array=&temp;
			return 0;
		}	
	}

	for(i=calendar->index ; i>place ; i--) /* move last 'place' meeting to the right */
	{
		calendar->array[i]=calendar->array[i-1];
	}
	calendar->array[i]=meeting;
	calendar->index++;					
	return 1;
}



int removeAppointment(Calendar_t* calendar, float begin_hour)
{
    int i=0, j=0;
    if(calendar!=NULL)
    {
	if((calendar->array)==NULL)
	{
		return 0;
	}
        for(i=0 ; i<(calendar->index) ; i++)
        {
            if((calendar->array[i]->start_time)==begin_hour)
	    {
	    	free(calendar->array[i]);
		for(j=i ; j<calendar->index-1 ; j++)
		{
			calendar->array[j]=calendar->array[j+1];
		}
		(calendar->index)--;
		return 1;
	    }
        }
    }
    
    return 0;
}


Meeting_t* findAppointment(Calendar_t* calendar, float begin_hour)
{
    int i=0;
    if(calendar!=NULL)
    {
        for(i=0 ; i<(calendar->index) ; i++)
        {
            if((calendar->array[i]->start_time)==begin_hour)
	    {
		return calendar->array[i];
	    }
        }
    }
    
    return NULL;
}


void loadFromFile(Calendar_t* calendar)
{
	int room=0;
	float start=0.0, end=0.0;
	Meeting_t* meeting;
	FILE* filePtr;
	filePtr=fopen("calendar.txt","r");
	if(filePtr!=NULL)
	{
		while(1)	
		{

			fscanf(filePtr,"%f%f%d",&start,&end,&room);	/* scan 3 variables from file */
			if(!feof(filePtr))
			{
				meeting=createMeeting(start,end,room);	/* create a meeting with the scanned info */

				insertAppointment(calendar,meeting);	/* insert the meeting to the calendar */
			}
			else
			{
				break;
			}
		}	
	}

	fclose(filePtr);
	return;
}

void storeToFile(Calendar_t* calendar)
{
	int room=0, i=0;
	float start=0.0, end=0.0;
	FILE* filePtr;
	filePtr=fopen("calendar.txt","w");
	if(filePtr==NULL)
	{
		return;
	}
	if(calendar!=NULL)
   	{
        	for(i=0 ; i<(calendar->index) ; i++) /* while the calendar is not empty, print to the file */
        	{
          		  fprintf(filePtr, "%f %f %d\n", calendar->array[i]->start_time, calendar->array[i]->end_time, calendar->array[i]->room_number);
       		}
        }
	
	fclose(filePtr);
	return;
}
