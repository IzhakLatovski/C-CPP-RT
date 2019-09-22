#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class string_t
{
	public:
		string_t();
		string_t(const char* nm);
		~string_t();
		string_t(const string_t& st);
		void operator=(const string_t &st);

		int length() const;
		void setString(const char* nm);
		const char* getString() const;
		int compare(string_t st2) const;
		void print() const;

	private:
		const char* name;
		
};

#endif