  
#ifndef MEMPAGE_H
#define MEMPAGE_H

#include "memManager.h"

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class memPage_t: public memManager_t{
   public:
      ~memPage_t();
      memPage_t();
      memPage_t(size_t capacity)
      {
           m_capacity=capacity;
      }
      size_t getCapacity() const
      {
            return m_capacity;
      }
      bool isFull() const;
      size_t setDefaultCapacity(size_t capacity)
      {
            m_defaultCapacity=capacity;
      }
      size_t getDefaultCapacity() const
      {
            return m_defaultCapacity;
      }
     
  private:
     size_t m_capacity;
     static size_t m_defaultCapacity;
