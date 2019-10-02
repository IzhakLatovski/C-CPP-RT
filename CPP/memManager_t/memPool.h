#ifndef MEMPOOL_H
#define MEMPOOL_H

#include "memManager.h"

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class memPool_t: public memManager_t
{
	public:

	  size_t setDefaultCapacity(size_t capacity)
      {
            m_defaultCapacity=capacity;
      }
      size_t getDefaultCapacity() const
      {
            return m_defaultCapacity;
      }
      size_t getPagesNumber() const
      {
      		return m_pagesNumber;
      }

	protected:

		virtual ~memPool_t()	/*Default destructor*/
		{
			for(int i=0 ; i<v.size() ; i++)
			{
				delete v[i];
			}
		}

		memPool_t()
		{
			memPool_t* pp=new memPool_t;
			v.insert(v.end(),pp);
		}				/*Default constructor*/

	private:
		vector<memPage_t*> v;
		size_t m_pagesNumber;

		memPool_t(const memPool_t &temp);
        memPool_t& operator=(const memPool_t& temp);
};