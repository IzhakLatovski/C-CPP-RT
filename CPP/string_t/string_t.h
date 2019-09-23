#ifndef STRING_H
#define STRING_H

#include <string.h>
#include <iostream>

using namespace std;

class string_t
{
	public:
		~string_t();							/*Destructor*/
		string_t();								/*Default constructor*/
		string_t(const char* str);				/*Type constructor*/
		string_t(const string_t& str);			/*Copy constructor*/
		void operator=(const string_t &str);
		int operator<(const string_t &str);
		int operator>(const string_t &str);
		int operator<=(const string_t &str);
		int operator>=(const string_t &str);
		int operator==(const string_t &str);
		int operator!=(const string_t &str);
		void operator+=(const string_t &str);
		void operator+=(const char* str);
		char& operator[](size_t index);
		char operator[](size_t index) const;

		int length() const;
		void setString(const char* str);
		const char* getString() const;
		int compare(const string_t str) const;
		void print() const;
		void toUpper();
		void toLower();
		void prepend(const string_t &str);
		void prepend(const char* str);
		int contains(const char* str) const;

	private:
		char* string;
		int stringLength;
};
	std::ostream& operator<<(std::ostream& os, const string_t &str);
	std::istream& operator>>(std::istream& is, string_t &str);

#endif
