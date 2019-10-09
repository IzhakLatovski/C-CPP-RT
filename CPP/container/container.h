#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <vector>
#include <list>
#include <typeinfo>
#include <iterator>
#include <algorithm>
#include "equal.h"

using namespace std;

template <class T, class C>
class tContainer_t
{	
	public:
		~tContainer_t() {};									// Destructor
		tContainer_t();										// Default constructor
		inline bool isEmpty()const;							// Is empty
		inline size_t numOfElements()const;					// Return the number of elements
		inline T* getFirst ()const;							// Return first element
		inline T* getLast ()const;							// Return last element
		inline void insert(T* element);						// Insert in the end
		inline T* findElement(const T& element)const;		// Find specific element by value
		inline T* removeElement(const T& element);			// Remove specific element and return pointer to it
		inline bool removeDeleteElement(const T& element);	// Remove specific element and delete
		inline void removeAllElements();					// Remove all elements, no delete
		inline void removeAllElementsDelete();				// Remove all elements and delete
		T* operator[](size_t ind)const;

	private:
		tContainer_t(const tContainer_t& container);		// No copy allowed
		void operator=(const tContainer_t& container);		// No copy allowed

		C m_container;

		typedef typename C::iterator iterator_t;
   		typedef typename C::const_iterator constIterator_t;
    	iterator_t itr;
    	constIterator_t constItr;
};

///////////////////////////////////////////////////////////////////////////////////////

template <class T, class C> bool tContainer_t<T, C>::isEmpty()const
{
	return m_container.empty();
}

template <class T, class C> bool tContainer_t<T, C>::numOfElements()const
{
	return m_container.size();
}

template <class T, class C> T* tContainer_t<T, C>::getFirst()const
{
	return *m_container.begin();
}

template <class T, class C> T* tContainer_t<T, C>::getLast()const
{
	return *m_container.back();
}

template <class T, class C> void tContainer_t<T, C>::insert(T* element)
{
	return m_container.push_back(element);
}

template <class T, class C> T* tContainer_t<T, C>::findElement(const T& element)const
{
	constItr=find_if(m_container.begin(),m_container.end(),equal_t(element));
	if(constItr==m_container.end())
	{
		return NULL;
	}
	else
	{
		T* ret=*constItr;
		return ret;
	}
}

template <class T, class C> T* tContainer_t<T, C>::removeElement(const T& element)
{
	itr=find_if(m_container.begin(),m_container.end(),equal_t(element));
	if(constItr==m_container.end())
	{
		return NULL;
	}
	else
	{
		T* ret=*itr;
		m_container.erase(itr);
		return ret;
	}
}

template <class T, class C> bool tContainer_t<T, C>::removeDeleteElement(const T& element)
{
	itr=find_if(m_container.begin(),m_container.end(),equal_t(element));
	if(constItr==m_container.end())
	{
		return false;
	}
	else
	{
		T* ret=*itr;
		m_container.erase(itr);
		delete ret;
		return true;
	}
}

template <class T, class C> void tContainer_t<T, C>::removeAllElements()
{
	m_container.clear();
}

template <class T, class C> void tContainer_t<T, C>::removeAllElementsDelete()
{
	itr=m_container.begin();  
    while(itr!=m_container.end())
    {   
        delete *itr;
        itr=m_container.begin();
    }
	m_container.clear();
}

template <class T, class C> T* tContainer_t<T, C>::operator[](size_t ind)const
{
	//if type==type
	//for(i=0 i<ind i++){iter++}
	//else vector[ind]
}

#endif