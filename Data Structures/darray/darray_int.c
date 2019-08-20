#include <stdlib.h>
#include "darray_int.h"

enum AdtStatus {OK, AllocationError}; ​

struct darray
{
	int* d_arr;
	size_t capacity;
	unsigned int index;
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
	if(dArr->index-1<dArr->capacity)
	{
		dArr->d_arr[dArr->index-1]=_item;
		dArr->index++;
	}
	else
	{
		dArr->d_arr=realloc(dArr->d_arr,sizeof(int)*dArr->capacity*2);
		if(dArr==NULL)
		{
			free(dArr->d_arr);
			free(dArr);
			return AllocationError;
		}
		dArr->d_arr[dArr->index-1]=_item;
		dArr->index++;
		dArr->capacity*=2;
	}

	return OK;
}


AdtStatus darrayDelete(darray *dArr,  int* _item)
{
	*_item=dArr->d_arr[dArr->index-1];
	dArr->index--;
	if(dArr->index==0.375*dArr->capacity)
	{
		dArr->d_arr=realloc(dArr->d_arr,sizeof(int)*dArr->capacity*0.5);
		dArr->capacity/=0.5;
	}
	return OK;
}


AdtStatus darrayGet(darray *dArr, size_t _index, int *_item)
{
	*_item=dArr->d_arr[_index-1];
	return OK;
}


AdtStatus darraySet(darray *dArr, size_t _index, int  _item)
{
	dArr->d_arr[_index-1]=_item;
	return OK;
}


AdtStatus darrayItemsNum(darray *dArr, int*  _numOfItems)
{
	*_numOfItems=dArr->index;
	return OK;
}

/*
​AdtStatus darraySort(darray *dArr, size_t arraySize)
{
	return OK;
}*/