#ifndef CALENDAR_H
#define CALENDAR_H

#include "meeting.h"
#include <map>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

class calendar_t
{
	public:
		~calendar_t();
		calendar_t() {};
		bool insertMeeting(const meeting_t* meeting);
		bool deleteMeeting(float begin);
		meeting_t* findMeeting(float begin)const;
		void cleanCalendar();

	private:
		map<float,meeting_t*> m_calendar;
		typedef typename map<float, meeting_t*>::iterator iter;
		typedef typename map<float, Meeting_t*>::const_iterator iterConst;
		calendar_t(const calendar_t& calendar) {};
		calendar_t& operator=(const calendar_t& calendar) {};
};

#endif