#ifndef MEMMANAGER_H
#define MEMMANAGER_H

#include <iostream>
#include <vector>

using namespace std;

class memManager_t
{
	public:
		bool isEmpty()
		{
			if(m_actualSize!=0)
			{
				return 0;
			}
			return 1;
		}
		size_t getCurrentPosition() const
		{
			return m_currentPosition;
		}
		bool setCurrentPosition(size_t position)
		{
			if(position>m_actualSize)
			{
				return 0;
			}
			else
			{
				m_currentPosition=position;
				return 1;
			}
		}
	protected:
		virtual ~memManager_t();	/*Default destructor*/
		memManager_t()				/*Default constructor*/
		{
			m_currentPosition=0;
			m_actualSize=0;
		}
		virtual size_t write(const void*,size_t);
		virtual size_t write(const void*,size_t,size_t position);
		virtual size_t read(size_t);
		virtual size_t read(size_t position,size_t);
	private:
	size_t m_currentPosition;
	size_t m_actualSize;
};
