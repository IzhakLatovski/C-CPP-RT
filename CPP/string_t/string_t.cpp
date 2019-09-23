#include "string_t.h"
#include <stdio.h>
#include <ctype.h>

#include <iostream>

using namespace std;

string_t::string_t()
{
	string=new char[32];
	string[0]='\0';
    len=0;
}

string_t::string_t(const char* str)
{
	string=new char[strlen(str)+1];
    strcpy(string,str);
    len=strlen(str);
}

string_t::~string_t()
{
    delete[] string;
}

string_t::string_t(const string_t& str)
{
	len=st.len;
	string=new char[len+1];
	strcpy(string,st.string);
}

void string_t::operator=(const string_t& str)
{
	if(this!=&st)
	{
		delete[] string;
		string=new char[st.len+1];
		strcpy(string,st.string);
	}
}

int string_t::length() const
{
	return len;
}

void string_t::setString(const char* str)
{
	strcpy(string,str);
	len=strlen(str);
}

const char* string_t::getString() const
{
	return string;
}

int string_t::compare(string_t st2) const
{
	int result=(strcmp(string,st2.string));
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
	printf("%s\n",string);
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

int string_t::operator<(const string_t& st)
{
	if(strcmp(string,st.string)<0)
	{
		return 1;
	}

	return 0;
}

int string_t::operator>(const string_t& st)
{
	if(strcmp(string,st.string)>0)
	{
		return 1;
	}
	
	return 0;
}

int string_t::operator<=(const string_t& st)
{
	if(strcmp(string,st.string)<0 || strcmp(string,st.string)==0)
	{
		return 1;
	}
	
	return 0;
}

int string_t::operator>=(const string_t& st)
{
	if(strcmp(string,st.string)>0 || strcmp(string,st.string)==0)
	{
		return 1;
	}
	
	return 0;
}

int string_t::operator==(const string_t& st)
{
	if(strcmp(string,st.string)==0)
	{
		return 1;
	}
	
	return 0;
}

int string_t::operator!=(const string_t& st)
{
	if(strcmp(string,st.string)==0)
	{
		return 0;
	}
	
	return 1;
}

void string_t::operator+=(const string_t &st)
{
	strcat(string,st.string);
	len+=strlen(st.getString());
}

void string_t::operator+=(const char* st)
{
	strcat(string,st);
	len+=strlen(st);
}

void string_t::prepend(const string_t &st2)
{
	char stringPre[128];
	strcpy(stringPre,st2.getString());
	strcat(stringPre,string);
	strcpy(string,stringPre);
	len+=strlen(st2.getString());
}

void string_t::prepend(const char* st)
{
	char stringPre[128];
	strcpy(stringPre,st);
	strcat(stringPre,string);
	strcpy(string,stringPre);	
	len+=strlen(st);
}

int string_t::contains(const char* st) const
{
	char* result;
	result=strstr(string,st);
	if(result==NULL)
	{
		return 0;
	}
	return 1;
}

char string_t::operator[](size_t index) const
{
	if(index>=len)
	{
		printf("Over boundry index!\n");
	}
	return string[index];
}

char& string_t::operator[](size_t index)
{
	if(index>=len)
	{
		printf("Over boundry index!\n");
	}
	return string[index];
}

std::ostream& operator<<(std::ostream& os, const string_t &st)
{
	os<<st.getString();
	return os;
}

std::istream& operator>>(std::istream& is, string_t &st)
{
	char temp[128];
	is>>temp;
	st.setString(temp);
	return is;
}
