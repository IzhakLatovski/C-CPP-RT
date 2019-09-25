#include "string_t.h"
#include <stdio.h>
#include <ctype.h>

#include <iostream>

using namespace std;

size_t string_t::defaultCapacity=64;
int string_t::caseSens=0;
size_t string_t::numberOfObjects=0;

string_t::string_t()
{
	string=new char[defaultCapacity];
	string[0]='\0';
    stringLength=0;
    stringCapacity=defaultCapacity;
    numberOfObjects++;
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
    numberOfObjects++;
}

string_t::~string_t()
{
	numberOfObjects--;
    delete[] string;
}

string_t::string_t(const string_t& str)
{
	size_t thisCapacity=getRightSize(str.string);
	string=new char[thisCapacity];
	strcpy(string,str.string);
	stringLength=strlen(str.string);
	stringCapacity=thisCapacity;
	numberOfObjects++;
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

int string_t::compare(const string_t& str)
{
	int result=0;
	if(getCaseSens())
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
	size_t thisSize=str.length()+stringLength+1;
	char* buffer=new char[thisSize];
	strcpy(buffer,str.getString());
	strcat(buffer,string);
	size_t thisCapacity=getRightSize(buffer);
	stringLength=str.length()+stringLength;
	delete[] string;
	string=new char[thisCapacity];
	strcpy(string,buffer);
	delete[] buffer;
	stringCapacity=thisCapacity;

/*
	char stringPre[128];
	strcpy(stringPre,str.getString());
	strcat(stringPre,string);
	strcpy(string,stringPre);
	stringLength+=strlen(str.getString());*/
}

void string_t::prepend(const char* str)
{
	size_t thisSize=strlen(str)+stringLength+1;
	char* buffer=new char[thisSize];
	strcpy(buffer,str);
	strcat(buffer,string);
	size_t thisCapacity=getRightSize(buffer);
	stringLength=strlen(str)+stringLength;
	delete[] string;
	string=new char[thisCapacity];
	strcpy(string,buffer);
	delete[] buffer;
	stringCapacity=thisCapacity;
}
	/*
	char stringPre[128];
	strcpy(stringPre,str);
	strcat(stringPre,string);
	strcpy(string,stringPre);	
	stringLength+=strlen(str);*/


int string_t::contains(const char* str) const
{
	char* result;
	if(getCaseSens())
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
{
	char temp[1024];
	is>>temp;
	str.setString(temp);
	return is;
}
/*************************************************************************************/
size_t string_t::firstOccurrence(const char c) const
{
	if(getCaseSens())
	{
		char* index=strchr(string,c);
		if(index!=NULL)
		{
			return index-string;
		}
		else
		{
			cout<<"No such first character"<<endl;
			return 0;
		}
	}
	else
	{
		string_t temp(string);
		temp.toLower();
		char* index=strchr(temp.string,tolower(c));
		if(index!=NULL)
		{
			return index-temp.string;
		}
		else
		{
			cout<<"No such first character"<<endl;
			return 0;
		}
	}
}

size_t string_t::lastOccurrence(const char c) const
{
	if(getCaseSens())
	{
		char* index=strrchr(string,c);
		if(index!=NULL)
		{
			return index-string;
		}
		else
		{
			cout<<"No such last character"<<endl;
			return 0;
		}
	}
	else
	{
		string_t temp(string);
		temp.toLower();
		char* index=strrchr(temp.string,tolower(c));
		if(index!=NULL)
		{
			return index-temp.string;
		}
		else
		{
			cout<<"No such first character"<<endl;
			return 0;
		}
	}
}

size_t string_t::getNumberOfObjects()
{
	return numberOfObjects;
}

string_t string_t::operator()(const size_t start, const size_t len) const
{
	if(stringLength<start+len)
	{
		cout<<"Not possible"<<endl;
		return NULL;
	}
	else
	{
		char* buffer=new char[len+1];
		int i=0;
		while(i<len)
		{
			buffer[i]=string[start+i];
			i++;
		}
		buffer[len]='\0';
		string_t newString(buffer);
		delete[] buffer;
		return newString;
	}
}
