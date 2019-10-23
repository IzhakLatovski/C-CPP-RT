#ifndef VIRTIO_H
#define VIRTIO_H

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

typedef enum status{ok_e, cant_open_file_e, bad_access_e, writeErr_e, readErr_e} status;

class virtIO_t
{
	public:
		// Functions
		~virtual virtIO_t();
		virtIO_t();
		virtIO_t(const string& name, const string& mode);
		status open(const string& name, const string& mode);
		void close();
		inline const string& getPath()const;
		inline const string& getAccess()const;
		inline const size_t getLength()const;
		inline void setPosition(size_t position;
		inline size_t getPosition()const;
		inline status getStatus()const;
		inline void setStatus(status stat;

		// Operators
		virtual virtIO_t& operator<<(char value)=0;
		virtual virtIO_t& operator>>(char& value)=0;
		virtual virtIO_t& operator<<(unsigned char value)=0;
		virtual virtIO_t& operator>>(unsigned char& value)=0;
		virtual virtIO_t& operator<<(short value)=0;
		virtual virtIO_t& operator>>(short& value)=0;
		virtual virtIO_t& operator<<(unsigned short value)=0;
		virtual virtIO_t& operator>>(unsigned short& value)=0;
		virtual virtIO_t& operator<<(int value)=0;
		virtual virtIO_t& operator>>(int& value)=0;
		virtual virtIO_t& operator<<(unsigned int value)=0;
		virtual virtIO_t& operator>>(unsigned int& value)=0;
		virtual virtIO_t& operator<<(long value)=0;
		virtual virtIO_t& operator>>(long& value)=0;
		virtual virtIO_t& operator<<(unsigned long value)=0;
		virtual virtIO_t& operator>>(unsigned long& value)=0;
		virtual virtIO_t& operator<<(float value)=0;
		virtual virtIO_t& operator>>(float& value)=0;
		virtual virtIO_t& operator<<(double value)=0;
		virtual virtIO_t& operator>>(double& value)=0;

	protected:
		FILE* m_file;
		string m_mode;
		string m_path;
		status m_status;
		// position? length?

	private:
		// No copy allowed
		virtIO_t(const virtIO_t& temp);
		virtIO_t& operator=(const virtIO_t& temp);
};


string& virtIO_t::getPath()const
{
	return m_path;
}

string& virtIO_t::getAccess()const
{
	return m_mode;
}

size_t virtIO_t::getLength()const
{
	fseek(m_file,0,SEEK_END);
	size_t result=ftell(m_file);
	fseek(m_file,0,SEEK_SET); // Restore position after counting

	return result;
}

void virtIO_t::setPosition(size_t position)
{
	if(position>this.getLength())
	{
		m_status=bad_access_e;
		return;
	}
	fseek(m_file,position,SEEK_SET);
}

size_t virtIO_t::getPosition()const
{
	return ftell(m_file);
}

status virtIO_t::getStatus()const
{
	return m_status;
}

void virtIO_t::setStatus(status stat)
{
	m_status=stat;
}

#endif