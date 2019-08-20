#include <stdlib.h>
#include "darray_int.h"

struct darray
{
	int* d_arr;
	size_t capacity;
	unsigned int index;
	size_t originalCapacity;
};
​

AdtStatus darrayCreate(darray **dArr, size_t initial_capacity)
{
	dArr=(darray*)malloc(sizeof(darray));
	if(dArr==NULL)
	{
		return AllocationError;
	}
	dArr->d_arr=(*int)malloc(sizeof(int)*initial_capacity);
	if(dArr->d_arr==NULL)
	{
		free(dArr);
		return AllocationError;
	}
	dArr->capacity=initial_capacity;
	dArr->index=0;
	dArr->originalCapacity=initial_capacity;

	return OK;
}


AdtStatus darrayDestroy(darray *dArr)
{
	if(dArr==NULL)
	{
		return AllocationError;
	}
	free(dArr->d_arr);
	free(dArr);

	return OK;
}


AdtStatus darrayAdd(darray *dArr,  int  _item)
{
	int* temp;

	if(dArr==NULL)
	{
		return AllocationError;
	}
	if(dArr->index-1<dArr->capacity)
	{
		dArr->d_arr[dArr->index-1]=_item;
		dArr->index++;
	}
	else
	{
		temp=realloc(dArr->d_arr,sizeof(int)*dArr->capacity*2);
		if(temp==NULL)
		{
			free(dArr->d_arr);
			free(dArr);
			return AllocationError;
		}
		dArr->d_arr=temp;
		dArr->d_arr[dArr->index-1]=_item;
		dArr->index++;
		dArr->capacity*=2;
	}

	return OK;
}


AdtStatus darrayDelete(darray *dArr,  int* _item)
{
	int* temp;

	if(dArr==NULL)
	{
		return AllocationError;
	}
	_item=&dArr->d_arr[dArr->index-1];
	dArr->index--;
	if((dArr->index<=0.375*dArr->capacity) && (dArr->capacity>dArr->originalCapacity))
	{
		temp=realloc(dArr->d_arr,sizeof(int)*dArr->capacity*0.5);
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


AdtStatus darrayGet(darray *dArr, size_t _index, int *_item)
{
	if(dArr==NULL)
	{
		return AllocationError;
	}
	if(_index>dArr->index-1)
	{
		return AllocationError;
	}
	_item=&dArr->d_arr[_index];

	return OK;
}


AdtStatus darraySet(darray *dArr, size_t _index, int  _item)
{
	if(dArr==NULL)
	{
		return AllocationError;
	}
	if(_index>dArr->index-1)
	{
		return AllocationError;
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
	_numOfItems=&dArr->index;

	return OK;
}


​AdtStatus darraySort(darray *dArr)
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
			if((*dArr->d_arr+j)>(*dArr->d_arr+j+1))
			{
				temp=*dArr->d_arr+j;
				*dArr->d_arr+j=*dArr->d_arr+j+1;
				*dArr->d_arr+j+1=temp;
			}
		}
	}

	return OK;
}