#include <stdio.h>
#include <stdlib.h>
#include "ad.h"



Calendar_t* createAd(int size)
{
    Calendar_t* calendar;
    calendar=malloc(sizeof(Calendar_t));
    if(calendar==NULL)
    {
        return NULL;
    }
    (calendar->array)=malloc((sizeof(Meeting_t))*size);
    if(calendar->array==NULL)
    {
        free(calendar);
        return NULL;
    }
    calendar->capacity=size;
    calendar->index=0;
    
    return calendar;
}


Meeting_t* createMeeting()
{
    Meeting_t* meeting;
    meeting=malloc(sizeof(Meeting_t));
    scanf("%f",&meeting->start_time);
    scanf("%f",&meeting->end_time);
    scanf("%d",&meeting->room_number);

    return meeting;
}


void destroyAd(Calendar_t* calendar)
{
    int i=0;
    for(i=0 ; i<(calendar->index) ; i++)
    {
        free(calendar->array[i]);
    }
    if(calendar!=NULL)
    {
        free(calendar->array);
        free(calendar);
    }
    
    return;
    
}


void printAd(Calendar_t* calendar)
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



/*

findAppointment
*/


int insertAppointment(Calendar_t* calendar, Meeting_t* meeting)
{
    if((calendar==NULL) || (meeting==NULL))
    {
	return -1;
    }  
    if((calendar->index)<(calendar->capacity))
    {
        calendar->array[calendar->index]=meeting;
        calendar->index++;
    }
    else
    {
       *(calendar->array)=(Meeting_t*)realloc(calendar->array,(calendar->capacity*2)*sizeof(Meeting_t*));
        if((calendar->array)==NULL)
        {
            return -1;
        }
        else
        {
            calendar->array[calendar->index]=meeting;
	    (calendar->index)++;
        }
    }
    return 0;
}


void removeAppointment(Calendar_t* calendar, float begin_hour)
{
    int i=0;
    if(calendar!=NULL)
    {
        for(i=0 ; i<(calendar->index) ; i++)
        {
            if((calendar->array[i]->start_time)==begin_hour)
	    {
	    	calendar->array[i]->start_time=0;
		calendar->array[i]->end_time=0;
		calendar->array[i]->room_number=555;
	    }
        }
    }
    
    return;
}
