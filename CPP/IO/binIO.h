#ifndef BINIO_H
#define BINIO_H

#include "virtIO.h"

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class binIO_t:public virtIO_t
{
	public:
		virtual ~binIO_t();
		binIO_t();
		binIO_t(const string& name, const string& mode);

		virtual virtIO_t& operator<<(char value)
		{
			//fwrite
		}
		virtual virtIO_t& operator>>(char& value)
		{
			//fread
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
};