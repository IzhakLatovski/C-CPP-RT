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
		string_t& operator=(const string_t &str);
		int operator<(const string_t &str)/********INLINE**********/
		{
			return (this->compare(str)==1) ? 1 : 0;
		}

		int operator>(const string_t &str)
		{
			return (this->compare(str)==2) ? 1 : 0;
		}
		int operator<=(const string_t &str)
		{
			return (this->compare(str)==1 || this->compare(str)==0) ? 1: 0;
		}
		int operator>=(const string_t &str)
		{
			return (this->compare(str)==2 || this->compare(str)==0) ? 1 : 0;
		}

		int operator==(const string_t &str)
		{
			return (this->compare(str)==0) ? 1 : 0;
		}

		int operator!=(const string_t &str)
		{
			return (this->compare(str)==0) ? 0 : 1;
		}

		void operator+=(const string_t &str);
		void operator+=(const char* str);
		char& operator[](size_t index);
		char operator[](size_t index) const;

		/*size_t length() const;*/
		size_t length() const/***************INLINE***************/
		{
			return stringLength;
		}

		void setString(const char* str);
		/*const char* getString() const;*/
		const char* getString() const/***********INLINE**************/
		{
			return string;
		}
		int compare(const string_t& str);
		/*void print() const;*/
		void print() const/***********INLINE***********/
		{
			cout<<string;
		}
		void toUpper();
		void toLower();
		void prepend(const string_t &str);
		void prepend(const char* str);
		int contains(const char* str) const;

		static int getCaseSens()/**************************INLINE****************/
		{
			return caseSens;
		}
		static void setCaseSens(const int value)/*******************INLINE*******/
		{
			caseSens=value;
		}

		static void setDefaultCapacity(const size_t value)/*******INLINE*******/
		{
			defaultCapacity=value;
		}
		static size_t getDefaultCapacity()/*************************INLINE*******/
		{
			return defaultCapacity;
		}
		size_t getStringCapacity()/*********************************INLINE*******/
		{
			return stringCapacity;
		}
		size_t firstOccurrence(const char c) const;
		size_t lastOccurrence(const char c) const;
		static size_t getNumberOfObjects();
		string_t operator()(const size_t start, const size_t len) const;

	private:
		char* string;
		size_t stringLength;
		size_t stringCapacity;
		static int caseSens;
		static size_t defaultCapacity;
		static size_t numberOfObjects;

		size_t getRightSize(const char* str) const
		{
			size_t rightCapacity=defaultCapacity;
			while((strlen(str)+1)>rightCapacity)
			{
				rightCapacity*=2;
			}
			return rightCapacity;
		}

};
	std::ostream& operator<<(std::ostream& os, const string_t &str);
	std::istream& operator>>(std::istream& is, string_t &str);

#endif
