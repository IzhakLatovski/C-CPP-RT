#include "string_t.h"

string_t::string_t()
{
	name="0";
}

string_t::string_t(const char* nm)
{
	name=nm;
}

string_t::~string_t()
{

}

string_t::string_t(const string_t& st)
{
	name=st.name;
}

void string_t::operator=(const string_t& st)
{
	if(this!=&st)
	{
		delete[] name;
		name=st.name;
	}
}

int string_t::length() const
{
	return strlen(name);
}

void string_t::setString(const char* nm)
{
	name=nm;
}

const char* string_t::getString() const
{
	return name;
}

int string_t::compare(string_t st2) const
{
	if(strcmp(name,st2.name)==0)
	{
		return 0;
	}
	else if (strcmp(name,st2.name)<0)
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