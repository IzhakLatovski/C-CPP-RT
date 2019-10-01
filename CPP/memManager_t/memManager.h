#ifndef MEMMANAGER_H
#define MEMMANAGER_H

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class memManager_t
{
	public:
		bool isEmpty()
		{
			return m_actualSize==0;
		}
		size_t getActualSize() const
		{
			return m_actualSize;	
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
		virtual size_t write(const void* buffer, size_t size);
		virtual size_t write(const void* buffer ,size_t size,size_t position);
		virtual size_t read(/*const void* buffer??*/size_t size);
		virtual size_t read(/*const void* buffer??*/size_t size,size_t position);
	private:
	size_t m_currentPosition;
	size_t m_actualSize;
	
	/*memManager_t(const memManager_t &temp){} copy 
        memManager_t& operator=(const memManager_t& temp){} operator= */
};
