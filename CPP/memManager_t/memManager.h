#ifndef MEMMANAGER_H
#define MEMMANAGER_H

#include <iostream>
#include <string.h>

using namespace std;

class memManager_t
{
	public:

		bool isEmpty() const
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
			try
			{
				if(position>m_actualSize)
				{
					throw 1;
				}
				else
				{
					m_currentPosition=position;
					return true;
				}
			}
			catch (int except)
			{
				cout<<"Exception with the position. Can't set"<<endl;
			}
		}

	protected:

		virtual ~memManager_t()=0;	/*Default destructor*/
		memManager_t()				/*Default constructor*/
		{
			m_currentPosition=0;
			m_actualSize=0;
		}
		virtual size_t write(const void* source, size_t size) {return 0;}
		virtual size_t write(const void* source ,size_t size, size_t position) {return 0;}
		virtual size_t read(void* target, size_t size) {return 0;}
		virtual size_t read(void* target, size_t size, size_t position) {return 0;}

	private:

		size_t m_currentPosition;
		size_t m_actualSize;
	
		memManager_t(const memManager_t &temp);
        memManager_t& operator=(const memManager_t& temp);
};
