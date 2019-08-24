#include <stdlib.h>
#include "darraygeneric.h"

static void swap(void **firstElement, void **secondElement);
static int partition (void** array, size_t first, size_t last, elementCompare compareFunc);
static void darrayQuickSort(darray *dArr, elementCompare compareFunc, int lower, int higher);



typedef struct darray
{
	void** d_arr;
	size_t capacity;
	size_t index;
	size_t originalCapacity;
} darray;



AdtStatus darrayCreate(darray **dArr, size_t initial_capacity)
{
    void* temp;
    darray* tempItem;
    temp=malloc(sizeof(void*)*initial_capacity);
    if(temp==NULL)
    {
        return AllocationError;
    }
	tempItem=malloc(sizeof(darray));
	if(tempItem==NULL)
	{
	    free(temp);
	    return AllocationError;
	}

	tempItem->capacity=initial_capacity;
	tempItem->index=0;
	tempItem->originalCapacity=initial_capacity;
	tempItem->d_arr=temp;
	*dArr=tempItem;

	return OK;
}


AdtStatus darrayDestroy(darray *dArr, elementDestroy destroyFunc, void *context)
{
	int i=0;

	if(dArr==NULL)
	{
		return AllocationError;
	}
	for(i=0 ; i<dArr->index ; i++)
	{
		destroyFunc(dArr->d_arr[i],context);
	}
	free(dArr->d_arr);
	free(dArr);

	return OK;
}


AdtStatus darrayAdd(darray *dArr,  void  *_item)
{
	void* temp;

	if(dArr==NULL)
	{
		return AllocationError;
	}
	if(dArr->index-1<dArr->capacity)
	{
		dArr->d_arr[dArr->index]=_item;
		dArr->index++;
	}
	else
	{
		temp=(void*)realloc(dArr->d_arr,sizeof(void*)*dArr->capacity*2);
		if(temp==NULL)
		{
			free(dArr->d_arr);
			free(dArr);
			return AllocationError;
		}
		dArr->d_arr=temp;
		dArr->d_arr[dArr->index]=_item;
		dArr->index++;
		dArr->capacity*=2;
	}

	return OK;
}


AdtStatus darrayDelete(darray *dArr,  void** _item)
{
	void* temp;

	if(dArr==NULL)
	{
		return AllocationError;
	}
	if(dArr->d_arr==NULL)
	{
		return AllocationError;
	}
	if(dArr->index==0)
	{
		return IndexError;
	}
	*_item=dArr->d_arr[dArr->index-1];
	dArr->index--;
	if((dArr->index<=0.375*dArr->capacity) && (dArr->capacity>dArr->originalCapacity))
	{
		temp=(void*)realloc(dArr->d_arr,sizeof(void*)*(dArr->capacity)*0.5);
		if(temp==NULL)
		{
			free(dArr->d_arr);
			free(dArr);
			return AllocationError;
		}
		dArr->d_arr=temp;
		dArr->capacity/=0.5;
	}
	return OK;
}


AdtStatus darrayGet(darray *dArr, size_t _index, void **_item)
{
	if(dArr==NULL)
	{
		return AllocationError;
	}
	if(_index>dArr->index-1)
	{
		return IndexError;
	}
	*_item=dArr->d_arr[_index];

	return OK;
}


AdtStatus darraySet(darray *dArr, size_t _index, void*  _item)
{
	if(dArr==NULL)
	{
		return AllocationError;
	}
	if(_index>dArr->index-1)
	{
		return IndexError;
	}
	dArr->d_arr[_index]=_item;

	return OK;
}


AdtStatus darrayItemsNum(darray *dArr, int*  _numOfItems)
{
	if(dArr==NULL)
	{
		return AllocationError;
	}
	*_numOfItems=dArr->index;

	return OK;
}


AdtStatus darraySort(darray *dArr, elementCompare compareFunc)
{
	if(dArr==NULL || dArr->d_arr==NULL)
	{
	    return AllocationError;
	}
	darrayQuickSort(darr,compareFunc,0,dArr->index-1);

	return OK;
}

static void swap(void **firstElement, void **secondElement) 
{ 
    void* temp = *firstElement; 
    *firstElement = *secondElement; 
    *secondElement = temp; 
    
    return;
} 

static int partition (void** array, size_t first, size_t last, elementCompare compareFunc)
{
    int i=first-1, j=0;
    void* pivot;

    pivot=array[last];
    for(j=first, j<=last, j++)
    {
        if(compareFunc(array[j],pivot)<=0)
        {
            i++;
            swap(array[i],array[j]);
        }
    }
   swap(&array[i+1],&array[last]);
   
   return (i+1);
}

static void darrayQuickSort(darray *dArr, elementCompare compareFunc, int lower, int higher)
{
    int part;
    if(lower<higher) 
    { 
        part=partition(dArr->m_arr,lower,higher,compareFunc); 
        darrayQuickSort(dArr,compareFunc,lower, part-1); 
        darrayQuickSort(dArr,compareFunc,part+1,higher); 
    }
    
    return;
}
