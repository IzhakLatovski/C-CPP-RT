#include "string_t.h"
#include <stdio.h>
#include <ctype.h>

#include <iostream>

using namespace std;

size_t string_t::defaultCapacity=64;
int string_t::caseSens=0;

string_t::string_t()
{
	string=new char[defaultCapacity];
	string[0]='\0';
    stringLength=0;
    stringCapacity=defaultCapacity;
}

string_t::string_t(const char* str)
{
	if(str==NULL)
	{
		string=new char[defaultCapacity];
		string[0]='\0';
    	stringLength=0;
        stringCapacity=defaultCapacity;
	}
	else
	{
		size_t thisCapacity=getRightSize(str);
		string=new char[thisCapacity];
    	strcpy(string,str);
    	stringLength=strlen(str);
    	stringCapacity=thisCapacity;
    }
}

string_t::~string_t()
{
    delete[] string;
}

string_t::string_t(const string_t& str)
{
	size_t thisCapacity=getRightSize(str.string);
	string=new char[thisCapacity];
	strcpy(string,str.string);
	stringLength=strlen(str.string);
	stringCapacity=thisCapacity;
}

string_t& string_t::operator=(const string_t& str)
{
	if(this!=&str)
	{
		delete[] string;
		string=new char[str.stringCapacity];
		strcpy(string,str.string);
		stringLength=str.length();
		stringCapacity=str.stringCapacity;
	}
	return *this;
}
/*
size_t string_t::length() const
{
	return stringLength;
}
*/
void string_t::setString(const char* str)
{
	delete[] string;
	if(str==NULL)
	{
		string=new char[defaultCapacity];
		string[0]='\0';
    	stringLength=0;
        stringCapacity=defaultCapacity;
	}
	else
	{
		size_t thisCapacity=getRightSize(str);
		string=new char[thisCapacity];
    	strcpy(string,str);
    	stringLength=strlen(str);
        stringCapacity=thisCapacity;
	}
}
/*
const char* string_t::getString() const
{
	return string;
}
*/
int string_t::compare(const string_t& str)
{
	int result=0;
	if(caseSens==1)
	{
		result=strcmp(string,str.string);
	}
	else
	{
		string_t temp1(string);
		string_t temp2(str);
		temp1.toLower();
		temp2.toLower();
		result=strcmp(temp1.string,temp2.string);
	}

	if(result==0)
	{
		return 0;
	}
	else if(result>0)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}
/*
void string_t::print() const
{
	cout<<string;
}
*/
/*********************************************************************************/
void string_t::toLower()
{
	int i=0;
	char c;
	while(string[i])
	{
		c=string[i];
		string[i]=tolower(c);
		i++;
	}
}

void string_t::toUpper()
{
	int i=0;
	char c;
	while(string[i])
	{
		c=string[i];
		string[i]=toupper(c);
		i++;
	}
}

int string_t::operator<(const string_t& str)
{
	if(this->compare(str)==1)
	{
		return 1;
	}

	return 0;
}

int string_t::operator>(const string_t& str)
{
	if(this->compare(str)==2)
	{
		return 1;
	}
	
	return 0;
}

int string_t::operator<=(const string_t& str)
{
	if(this->compare(str)==1 || this->compare(str)==0)
	{
		return 1;
	}
	
	return 0;
}

int string_t::operator>=(const string_t& str)
{
	if(this->compare(str)==2 || this->compare(str)==0)
	{
		return 1;
	}
	
	return 0;
}

int string_t::operator==(const string_t& str)
{
	if(this->compare(str)==0)
	{
		return 1;
	}
	
	return 0;
}

int string_t::operator!=(const string_t& str)
{
	if(this->compare(str)==0)
	{
		return 0;
	}
	
	return 1;
}

void string_t::operator+=(const string_t &str)
{
	size_t thisSize=str.length()+stringLength+1;
	char* buffer=new char[thisSize];
	strcpy(buffer,string);
	strcat(buffer,str.string);
	size_t thisCapacity=getRightSize(buffer);
	stringLength=str.length()+stringLength;
	delete[] string;
	string=new char[thisCapacity];
	strcpy(string,buffer);
	delete[] buffer;
	stringCapacity=thisCapacity;
}

void string_t::operator+=(const char* str)
{
	size_t thisSize=strlen(str)+stringLength+1;
	char* buffer=new char[thisSize];
	strcpy(buffer,string);
	strcat(buffer,str);
	size_t thisCapacity=getRightSize(buffer);
	stringLength=strlen(str)+stringLength;
	delete[] string;
	string=new char[thisCapacity];
	strcpy(string,buffer);
	delete[] buffer;
	stringCapacity=thisCapacity;
}

void string_t::prepend(const string_t &str)
{
	char stringPre[128];
	strcpy(stringPre,str.getString());
	strcat(stringPre,string);
	strcpy(string,stringPre);
	stringLength+=strlen(str.getString());
}

void string_t::prepend(const char* str)
{
	char stringPre[128];
	strcpy(stringPre,str);
	strcat(stringPre,string);
	strcpy(string,stringPre);	
	stringLength+=strlen(str);
}

int string_t::contains(const char* str) const
{
	char* result;
	if(caseSens==1)
	{
		result=strstr(string,str);
	}
	else
	{
		result=strcasestr(string,str);
	}
	if(result==NULL)
	{
		return 0;
	}
	return 1;
}

char string_t::operator[](size_t index) const
{
	if(index>=stringLength)
	{
		cout<<"Over boundry index";
	}
	return string[index];
}

char& string_t::operator[](size_t index)
{
	if(index>=stringLength)
	{
		cout<<"Over boundry index";
	}
	return string[index];
}

std::ostream& operator<<(std::ostream& os, const string_t &str)
{
	os<<str.getString();
	return os;
}

std::istream& operator>>(std::istream& is, string_t &str)
{/*
	size_t thisSize=strlen(is);
	char* buffer=new char[thisSize];
	strcpy(buffer,str.string);
	size_t thisCapacity=getRightSize(buffer);
	stringLength=str.length();
	delete[] string;
	string=new char[thisCapacity];
	delete[] buffer;
	stringCapacity=thisCapacity;
*/
	char temp[1024];
	is>>temp;
	str.setString(temp);
	return is;
}
/*************************************************************************************/
/*
void string_t::setDefaultCapacity(const size_t value)
{
	defaultCapacity=value;
}
*//*
size_t string_t::getDefaultCapacity() 
{
	return defaultCapacity;
}*/
/*
size_t string_t::getStringCapacity() 
{
	return stringCapacity;
}
*//*
void string_t::setCaseSens(const int value)
{
	caseSens=value;
}
*//*
int string_t::getCaseSens()
{
	return caseSens;
}*/

size_t string_t::firstOccurrence(const char c) const
{
	char* index=strchr(string,c);
	if(index)
	{
		return index-string;
	}
}
