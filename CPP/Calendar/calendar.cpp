#include "meeting.h"
#include "calendar.h"
#include <map>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

calendar_t::~calendar_t()
{
	for(iter=m_calendar.begin() ; iter!=m_calendar.end() ; iter++)
	{
		delete(iter->second);
	}
	m_calendar.clear();
}

void calendar_t::cleanCalendar()
{
	for(iter itr=m_calendar.begin() ; itr!=m_calendar.end() ; itr++)
	{
		delete(itr->second);
	}
	m_calendar.clear();
}

bool calendar_t::insertMeeting(meeting_t* meeting)
{
	if(meeting==0)
	{
		return false;
	}
	
}

bool calendar_t::deleteMeeting(float begin)
{
	iter itr=m_calendar.find(begin);
	if(itr==m_calendar.end())
	{
		return false;
	}
	else
	{
		delete(it->second);
		m_calendar.erase(it);
	}
	return true;
}

meeting_t* calendar_t::findMeeting(float begin)const
{
	iterConst itr=m_calendar.find(begin);
	if(itr==m_calendar.end())
	{
		throw(1);
	}
	else
	{
		return (it->second);
	}
}