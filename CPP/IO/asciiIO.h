#ifndef ASCIIIO_H
#define ASCIIIO_H

#include "virtIO.h"

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class asciiIO_t:public virtIO_t
{
	public:
		virtual ~asciiIO_t();
		asciiIO_t();
		asciiIO_t(const string& name, const string& mode);

		virtual virtIO_t& operator<<(char value)
		{
			checkForOut();
			if(!=(fprintf(m_file,/*"%c"*/,value)))
			{
				m_status=writeErr_e;
			}
		}
		virtual virtIO_t& operator>>(char& value)
		{
			checkForIn();
			if(!=(fscanf(m_file,/*"%c"*/,value)))
			{
				m_status=readErr_e;
			}
		}
		virtual virtIO_t& operator<<(unsigned char value)
		{

		}
		virtual virtIO_t& operator>>(unsigned char& value)
		{

		}
		virtual virtIO_t& operator<<(short value)
		{

		}
		virtual virtIO_t& operator>>(short& value)
		{

		}
		virtual virtIO_t& operator<<(unsigned short value)
		{

		}
		virtual virtIO_t& operator>>(unsigned short& value)
		{

		}
		virtual virtIO_t& operator<<(int value)
		{

		}
		virtual virtIO_t& operator>>(int& value)
		{

		}
		virtual virtIO_t& operator<<(unsigned int value)
		{

		}
		virtual virtIO_t& operator>>(unsigned int& value)
		{

		}
		virtual virtIO_t& operator<<(long value)
		{

		}
		virtual virtIO_t& operator>>(long& value)
		{

		}
		virtual virtIO_t& operator<<(unsigned long value)
		{

		}
		virtual virtIO_t& operator>>(unsigned long& value)
		{

		}
		virtual virtIO_t& operator<<(float value)
		{

		}
		virtual virtIO_t& operator>>(float& value)
		{

		}
		virtual virtIO_t& operator<<(double value)
		{

		}
		virtual virtIO_t& operator>>(double& value)
		{
			
		}

	private:
		asciiIO_t(const asciiIO_t& temp);
		asciiIO_t& operator=(const asciiIO_t& temp);
};