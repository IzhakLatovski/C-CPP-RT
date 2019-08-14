#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "new.h"


char* monthNames[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
int daysInMonth[12]={31,29,31,30,31,30,31,31,30,31,30,31};

/*VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV--TIME--VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV*/

int timeIsLegal(int hour, int minute, int second);



int setNewTime(cTime_t* object, int hour, int minute, int second)
{
	if(timeIsLegal(hour,minute,second)==0)
	{
		return -1;
	}

	object->m_hour=hour;
	object->m_minute=minute;
	object->m_second=second;

	return 0;
}


void printTime(cTime_t* object, int format)
{
	char* formatLetters;

	if(format==1)
	{
		printf("%d:%d:%d\n", object->m_hour, object->m_minute, object->m_second);
	}
	else
	{
		if(object->m_hour<12)
		{
			formatLetters="AM";

		}
		else
		{
			formatLetters="PM";
		
		}
		printf("%d:%d:%d %s\n", (object->m_hour)%12, object->m_minute, object->m_second, formatLetters);
	}

	return;
}


int getHour(cTime_t* object)
{
 	return object->m_hour;
}


int getMinute(cTime_t* object)
{
	return object->m_minute;
}


int getSecond(cTime_t* object)
{
	return object->m_second;
}


void addTimes(cTime_t* firstObject, cTime_t* secondObject)
{
	int second=0, minute=0, hour=0;
	
	second=getSecond(firstObject)+getSecond(secondObject);
	minute=getMinute(firstObject)+getMinute(secondObject)+(second/60);
	hour=getHour(firstObject)+getHour(secondObject)+(minute/60);

	setNewTime(firstObject,hour%24,minute%60,second%60);

	return;
}



/* -------INTERNAL FUNCTION------- */
int timeIsLegal(int hour, int minute, int second)
{
	if(hour<0 || hour >=24 || minute<0 || minute>59 || second<0 || second>59)
	{
		return 0;
	}

	return 1;
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^--TIME--^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/



/*VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV--DATE--VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV*/


int setNewDate(cDate_t* object, int day, int month, int year)
{
	if(dateIsLegal(day,month,year)==0)
	{
		return -1;
	}

	object->m_day=day;
	object->m_month=month;
	object->m_year=year;

	return 0;
}

void printDate(cDate_t* object, int format)
{
	if(format==1)
	{
		printf("%d/%s/%d\n", object->m_day, monthNames[object->m_month-1], object->m_year);
	}
	else if(format==2)
	{
		printf("%d/%d/%d\n", object->m_day, object->m_month, object->m_year);
	}
	else if(format==3)
	{
		printf("%d/%d/%d\n", object->m_month, object->m_day, object->m_year);
	}
}


int getDay(cDate_t* object)
{
	return object->m_day;
}
int getMonth(cDate_t* object)
{
	return object->m_month;
}
int getYear(cDate_t* object)
{
	return object->m_year;
}


char* getMonthName(cDate_t* object)
{
	return monthNames[object->m_month-1];
}
int isLeapYear(cDate_t* object)
{
	if((object->m_year)%4==0)
	{
		return 1;
	}

	return 0;
}


int getDayOfYear(cDate_t* object)
{
	int i=0, day=0;

	for(i=0 ; i<object->m_month ; i++)
	{
		day+=daysInMonth[i];
	}
	day+=object->m_day;
	if(isLeapYear==0)
	{
		day--;
	}

	return day;
}


void addDates(cDate_t* firstObject, cDate_t* secondObject)
{
	/* HAVE TO DEAL WITH LEAP YEARS HERE */
	int day=0, month=0, year=0;
	int firstObjectDaysInMonth=daysInMonth[firstObject->m_month-1];
	day=getDay(firstObject)+getDay(secondObject);
	month=getMonth(firstObject)+getMonth(secondObject)+(day/firstObjectDaysInMonth);
	year=getYear(firstObject)+getYear(secondObject)+(month/12);

	setNewDate(firstObject,day%firstObjectDaysInMonth,month%12,year);

	return;
}


/* -------INTERNAL FUNCTION------- */
int dateIsLegal(int day, int month, int year)
{
	if(day<1 || day >31 || month<1 || month>12 || year<0 || day>daysInMonth[month-1])
	{
		return 0;
	}
	if(month==2 && day==29 && (isLeapYear==0))
	{
		return 0;
	}

	return 1;
}





/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^--DATE--^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/