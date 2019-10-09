#ifndef EQUAL_H
#define EQUAL_H

#include <iostream>
#include <vector>
#include <list>
#include <typeinfo>
#include <iterator>
#include <algorithm>

using namespace std;

template <class T>
class equal_t
{	
	public:
		equal_t(const T& value):m_value(value) {};
		bool operator()(const T* value)const {return (*value==m_value);};

	private:
		T m_value;
};

#endif