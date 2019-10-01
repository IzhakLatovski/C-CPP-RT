#include "memManager.h"

#include <iostream>
#include <string.h>

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
     
  private:
     size_t m_capacity;
