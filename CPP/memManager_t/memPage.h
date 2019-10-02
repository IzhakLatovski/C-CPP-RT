#ifndef MEMPAGE_H
#define MEMPAGE_H

#include "memManager.h"

#include <iostream>
#include <string.h>

using namespace std;

class memPage_t: public memManager_t
{
   public:

      virtual ~memPage_t()
      {
           delete[] m_stream;
      }
      memPage_t()
      {
           m_capacity=6;
           m_stream=new char[6];
      }
      memPage_t(size_t capacity)
      {
           m_capacity=capacity;
           m_stream=new char[capacity];
      }
      size_t getCapacity() const
      {
            return m_capacity;
      }
      bool isFull() const
      {
            if(this.getActualSize()==m_capacity)
            {
                  return true;
            }
            return false;
      }

  protected:
      virtual size_t write(const void* source, size_t size)
      {
          if(size<(m_capacity-m_actualSize))
          {
              memcpy(m_stream[m_currentPosition],source,size);
          }
      }
      virtual size_t write(const void* source, size_t size, size_t position)
      {
          if(size<(m_capacity-m_actualSize))
          {
              memcpy(m_stream[position],source,size);
          }
      }
      virtual size_t read(void* target, size_t size)
        {
            if(size<(m_capacity-m_actualSize))
            {
                memcpy(target, m_stream[m_currentPosition],size);
            }
        }
        virtual size_t read(void* target, size_t size, size_t position)
        {
            if(size<(m_capacity-m_actualSize))
            {
                memcpy(target, m_stream[position],size);
            }
        }

  private:

     size_t m_capacity;
     char* m_stream;
     static size_t m_defaultCapacity;

     memPage_t(const memPage& temp);
     memManager_t& operator=(const memManager_t& temp);

};
