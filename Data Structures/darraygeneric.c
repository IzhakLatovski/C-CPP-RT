#include <stdlib.h>
#include <stdio.h>
#include "darraygeneric.h"

struct darray
{
	void** d_arr;
	size_t capacity;
	size_t index;
	size_t originalCapacity;
};


static void quicksort(darray* dArr,size_t first,size_t last,elementCompare compareFunc)
{
	size_t i=0, j=0, pivot=0;
       void* temp;
	if(first<last)
	{
    	pivot=first;
    	i=first;
    	j=last;
	    while(i<j)
	    {
	        while(compareFunc(dArr->d_arr[i],dArr->d_arr[pivot])<=0 && i<last)
	        {
	        	i++;
	        }
	        while(compareFunc(dArr->d_arr[j],dArr->d_arr[pivot])>0)
	        {
	      	 	j--;
	      	}
		    if(i<j)
		    {
		            temp=dArr->d_arr[i];
		            dArr->d_arr[i]=dArr->d_arr[j];
		            dArr->d_arr[j]=temp;
		    }
	    }
	    temp=dArr->d_arr[pivot];
	    dArr->d_arr[pivot]=dArr->d_arr[j];
	    dArr->d_arr[j]=temp;
	    quicksort(dArr,first,j-1,compareFunc);
	    quicksort(dArr,j+1,last,compareFunc);
}


AdtStatus darrayCreate(darray **dArr, size_t initial_capacity)
{
	*dArr=malloc(sizeof(darray));
	if(*dArr==NULL)
	{
		return AllocationError;
	}
	(*dArr)->d_arr=malloc(sizeof(void*)*initial_capacity);
	if((*dArr)->d_arr==NULL)
	{
		free(*dArr);
		return AllocationError;
	}
	(*dArr)->capacity=initial_capacity;
	(*dArr)->index=0;
	(*dArr)->originalCapacity=initial_capacity;

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
	void** temp;

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
		temp=realloc(dArr->d_arr,sizeof(void*)*dArr->capacity*2);
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
	void** temp;

	if(dArr==NULL)
	{
		return AllocationError;
	}
	if(dArr->index==0)
	{
		return IndexError;
	}
	*_item=dArr->d_arr[dArr->index];
	dArr->index--;
	if((dArr->index<=0.375*dArr->capacity) && (dArr->capacity>dArr->originalCapacity))
	{
		temp=realloc(dArr->d_arr,sizeof(void*)*(dArr->capacity)*0.5);
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
	int i=0, j=0, temp=0;

	if(dArr==NULL)
	{
		return AllocationError;
	}
	for(i=1 ; i<dArr->index ; i++)
	{
		for(j=0 ; j<dArr->index-i ; j++)
		{
			if((*dArr->d_arr+j)>*(dArr->d_arr+j+1))
			{
				temp=dArr->d_arr[j];
				(dArr->d_arr[j])=(dArr->d_arr[j+1]);
				(dArr->d_arr[j+1])=temp;
			}
		}
	}

	return OK;
}
