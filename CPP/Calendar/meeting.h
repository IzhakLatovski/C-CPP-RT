#ifndef MEETING_H
#define MEETING_H

#include <string>

using namespace std;

class meeting_t
{
	public:
		~meeting_t() {};
		meeting_t(const string& subject, float begin, float end);
		const string& getSubject()const {return m_subject;};
		float getBegin()const {return m_begin;};
		float getEnd()const {return m_end;};

	private:
		string m_subject;
		float m_begin;
		float m_end;

		meeting_t(const meeting_t& meeting) {};				// no copy, can't overlap
		meeting_t& operator=(const meeting_t& meeting) {};	// no copy, can't overlap
};

#endif