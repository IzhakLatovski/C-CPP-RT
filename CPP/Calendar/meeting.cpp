#ifndef MEETING_H
#define MEETING_H

#include "meeting.h"
#include <string>

using namespace std;

meeting_t::meeting_t(const string& subject, float begin, float end):m_subject(subject)
{
	if(begin<0 || end>24)
	{
		throw(1);
	}
	else if(begin>=end)
	{
		throw(2);
	}
	else
	{
		m_begin=begin;
		m_end=end;
	}
}