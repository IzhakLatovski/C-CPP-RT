#include "string_t.h"

string_t::string_t()
{

}

string_t::string_t(const char* nm)
{
	name=new char[strlen(nm)+1];
	strcpy(name,nm);
}

string_t::~string_t()
{
	delete[] name;
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
	delete[] name;
	strcpy(name,nm);
}

const char* string_t::getString() const
{
	return name;
}

int string_t::compare(string_t st2) const
{
	return strcmp(name,st2.name);
}

void string_t::print() const
{
	std::cout<<name;
}