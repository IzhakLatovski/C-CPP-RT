#ifndef STRING_H
#define STRING_H

#include <string.h>

class string_t
{
	public:
		~string_t();							/*Destructor*/
		string_t();								/*Default constructor*/
		string_t(const char* nm);				/*Type constructor*/
		string_t(const string_t& st);			/*Copy constructor*/
		void operator=(const string_t &st);
		int operator<(const string_t &st);
		int operator>(const string_t &st);
		int operator<=(const string_t &st);
		int operator>=(const string_t &st);
		int operator==(const string_t &st);
		int operator!=(const string_t &st);

		int length() const;
		void setString(const char* nm);
		const char* getString() const;
		int compare(const string_t st2) const;
		void print() const;
		void toUpper();
		void toLower();

	private:
		char* name;
		int len;
};

#endif
