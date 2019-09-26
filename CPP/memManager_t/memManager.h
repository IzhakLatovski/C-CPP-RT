#ifndef MEMMANAGER_H
#define MEMMANAGER_H

#include <iostream>
#include <vector>

using namespace std;

class memManager_t
{
	public:
		bool isEmpty();
		size_t getCurrentPosition();
		size_t setCurrentPosition(size_t position);
	protected:
		virtual ~memManager_t();	/*Default destructor*/
		memManager_t();				/*Default constructor*/

		virtual size_t write(const void*,size_t);
		virtual size_t write(const void*,size_t,size_t position);
		virtual size_t read(size_t);
		virtual size_t read(size_t position,size_t);
	private:
	size_t m_currentPosition;
	size_t m_capacity;
};