#ifndef STRING_H
#define STRING_H

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
		int compare(const string_t st2) const;
		void print() const;

	private:
		char* name;
		int len;
};

#endif
