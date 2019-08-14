#ifndef TIME_H
#define TIME_H


typedef struct
	{
		int m_hour;
		int m_minute;
		int m_second;
	} cTime_t;

typedef struct
	{
		int m_year;
		int m_month;
		int m_day;
	} cDate_t;


/*VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV--TIME--VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV*/

int setNewTime(cTime_t* object, int hour, int minute, int second);
void printTime(cTime_t* object, int format);
int getHour(cTime_t* object);
int getMinute(cTime_t* object);
int getSecond(cTime_t* object);
void addTimes(cTime_t* time1, cTime_t* time2);

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^--TIME--^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/


/*VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV--DATE--VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV*/

int setNewDate(cDate_t* object, int day, int month, int year);
void printDate(cDate_t* object, int format);
int getDay(cDate_t* object);
int getMonth(cDate_t* object);
int getYear(cDate_t* object);
int getDayOfYear(cDate_t* object);
char* getNMonthName(cDate_t* object);
int isLeapYear(cDate_t* object);
void addDates(cDate_t* firstObject, cDate_t* secondObject);

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^--DATE--^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/


#endif