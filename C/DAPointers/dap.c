#include <stdio.h>
#include <stdlib.h>
#include "dap.h"



Array_t* createArray(int capacity)
{
    Array_t* array;
    array=(Array_t*)malloc(sizeof(Array_t));
    if(array==NULL)
    {
        return NULL;
    }
    array->capacity=capacity;
    array->index=0;
    array->arr=(Array_t*)malloc(capacity*(sizeof(intPtr))); /*  */
    if(array->arr==NULL)
    {
        free(array);
        return NULL;
    }
    return array;
}



int insert(Array_t* array, intPtr numberPtr) /*  */
{
    if((array==NULL) || (numberPtr==NULL))  /*  */
    {
	return -1;
    }  
    intPtr array_adress=array->arr;
    if((array->index)<(array->capacity))
    {
        array->arr[array->index]=*number;  /*  */
        array->index++;
    }
    else
    {
        array->arr=(intPtr*)realloc(array->arr,(array->capacity*2)*sizeof(intPtr)); /*  */
        if((array->arr)==NULL)
        {
            array->arr=array_adress;
            return -1;
        }
        else
        {
            array->arr[array->index]=number; /* */
	    (array->index)++;
        }
    }
    return 0;
}



void print(Array_t* array)  /*  */
{
    int i=0;
    if((array!=NULL) && (array->arr!=NULL) )
    {
        for(i=0 ; i<(array->index) ; i++)
	{
		if(array->arr[i]!=NULL)
		{
		    printf("%d ",*(array->arr[i]));  /*  */
		}
	}
    }
    printf("/n");
    return;
}



void destroy(Array_t* array)
{
    int i=0;
    if((array!=NULL) && (array->arr!=NULL))
    {    
	    for(i=0 ; i<(array->index) ; i++)	/* */
	    {
		free(array->arr[i];
	    }
    }
    free(array->arr);
    free(array);

    return;
}
