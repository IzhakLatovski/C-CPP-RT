#include <iostream>
#include <vector>
#include <list>
#include <typeinfo>
#include <iterator>
#include <algorithm>

#include "container.h"

using namespace std;

template <class T, class C> tContainer_t<T, C>::~tContainer_t()
{
	while(!m_container.empty())
	{
    	m_container.pop_back();
	}
}