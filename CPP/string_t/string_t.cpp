#include "string_t.h"
#include <stdio.h>
#include <ctype.h>

#include <iostream>

using namespace std;

string_t::string_t()
{
	string=new char[32];
	string[0]='\0';
    stringLength=0;
}

string_t::string_t(const char* str)
{
	string=new char[strlen(str)+1];
    strcpy(string,str);
    stringLength=strlen(str);
}

string_t::~string_t()
{
    delete[] string;
}

string_t::string_t(const string_t& str)
{
	stringLength=str.stringLength;
	string=new char[stringLength+1];
	strcpy(string,str.string);
}

void string_t::operator=(const string_t& str)
{
	if(this!=&str)
	{
		delete[] string;
		string=new char[str.stringLength+1];
		strcpy(string,str.string);
	}
}

int string_t::length() const
{
	return stringLength;
}

void string_t::setString(const char* str)
{
	strcpy(string,str);
	stringLength=strlen(str);
}

const char* string_t::getString() const
{
	return string;
}

int string_t::compare(string_t str) const
{
	int result=(strcmp(string,str.string));
	if(result==0)
	{
		return 0;
	}
	else if(result>0)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

void string_t::print() const
{
	cout<<string;
	/*printf("%s\n",string);*/
}
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
	if(strcmp(string,str.string)<0)
	{
		return 1;
	}

	return 0;
}

int string_t::operator>(const string_t& str)
{
	if(strcmp(string,str.string)>0)
	{
		return 1;
	}
	
	return 0;
}

int string_t::operator<=(const string_t& str)
{
	if(strcmp(string,str.string)<0 || strcmp(string,str.string)==0)
	{
		return 1;
	}
	
	return 0;
}

int string_t::operator>=(const string_t& str)
{
	if(strcmp(string,str.string)>0 || strcmp(string,str.string)==0)
	{
		return 1;
	}
	
	return 0;
}

int string_t::operator==(const string_t& str)
{
	if(strcmp(string,str.string)==0)
	{
		return 1;
	}
	
	return 0;
}

int string_t::operator!=(const string_t& str)
{
	if(strcmp(string,str.string)==0)
	{
		return 0;
	}
	
	return 1;
}

void string_t::operator+=(const string_t &str)
{
	strcat(string,str.string);
	stringLength+=strlen(str.getString());
}

void string_t::operator+=(const char* str)
{
	strcat(string,str);
	stringLength+=strlen(str);
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
	result=strstr(string,str);
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
		/*printf("Over boundry index!\n");*/
	}
	return string[index];
}

char& string_t::operator[](size_t index)
{
	if(index>=stringLength)
	{
		cout<<"Over boundry index";
		/*printf("Over boundry index!\n");*/
	}
	return string[index];
}

std::ostream& operator<<(std::ostream& os, const string_t &str)
{
	os<<str.getString();
	return os;
}

std::istream& operator>>(std::istream& is, string_t &str)
{
	char temp[128];
	is>>temp;
	str.setString(temp);
	return is;
}
