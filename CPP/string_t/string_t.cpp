#include "string_t.h"
#include <stdio.h>
#include <ctype.h>

string_t::string_t()
{
	name=new char[32];
	name[0]='\0';
    len=0;
}

string_t::string_t(const char* nm)
{
	name=new char[strlen(nm)+1];
    strcpy(name,nm);
    len=strlen(nm);
}

string_t::~string_t()
{
    delete[] name;
}

string_t::string_t(const string_t& st)
{
	len=st.len;
	name=new char[len+1];
	strcpy(name,st.name);
}

void string_t::operator=(const string_t& st)
{
	if(this!=&st)
	{
		delete[] name;
		name=new char[st.len+1];
		strcpy(name,st.name);
	}
}

int string_t::length() const
{
	return len;
}

void string_t::setString(const char* nm)
{
	strcpy(name,nm);
	len=strlen(nm);
}

const char* string_t::getString() const
{
	return name;
}

int string_t::compare(string_t st2) const
{
	int result=(strcmp(name,st2.name));
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
	printf("%s\n",name);
}
/*********************************************************************************/
void string_t::toLower()
{
	int i=0;
	char c;
	while(name[i])
	{
		c=name[i];
		name[i]=tolower(c);
		i++;
	}
}

void string_t::toUpper()
{
	int i=0;
	char c;
	while(name[i])
	{
		c=name[i];
		name[i]=toupper(c);
		i++;
	}
}

int string_t::operator<(const string_t& st)
{
	if(strcmp(name,st.name)<0)
	{
		return 1;
	}

	return 0;
}

int string_t::operator>(const string_t& st)
{
	if(strcmp(name,st.name)>0)
	{
		return 1;
	}
	
	return 0;
}

int string_t::operator<=(const string_t& st)
{
	if(strcmp(name,st.name)<0 || strcmp(name,st.name)==0)
	{
		return 1;
	}
	
	return 0;
}

int string_t::operator>=(const string_t& st)
{
	if(strcmp(name,st.name)>0 || strcmp(name,st.name)==0)
	{
		return 1;
	}
	
	return 0;
}

int string_t::operator==(const string_t& st)
{
	if(strcmp(name,st.name)==0)
	{
		return 1;
	}
	
	return 0;
}

int string_t::operator!=(const string_t& st)
{
	if(strcmp(name,st.name)==0)
	{
		return 0;
	}
	
	return 1;
}
