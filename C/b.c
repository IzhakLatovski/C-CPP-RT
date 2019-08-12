#include <stdio.h>
#include <stdlib.h>
#include "da.h"



Array_t* createArray(int capacity)
{
    Array_t* array;
    array=malloc(sizeof(Array_t));
    if(array==NULL)
    {
        return NULL;
    }
    array->arr=malloc(capacity*(sizeof(int*))); /*  */
    if(array->arr==NULL)
    {
        free(array);
        return NULL;
    }
    array->capacity=capacity;
    array->index=0;
    return array;
}



int insert(Array_t* array, int* numberPtr) /*  */
{
    if((array==NULL) || (numberPtr==NULL))  /*  */
    {
	return -1;
    }  
    int* array_adress=array->arr;
    if((array->index)<(array->capacity))
    {
        array->arr[array->index]=*number;  /*  */
        array->index++;
    }
    else
    {
        array->arr=(int*)realloc(array->arr,(array->capacity*2)*sizeof(int*)); /*  */
        if((array->arr)==NULL)
        {
            array->arr=array_adress;
            return -1;
        }
        else
        {
            array->arr[array->index]=*number; /* */
	    array->index++;
        }
    }
    return 1;
}



void print(Array_t** array)  /*  */
{
    int i=0;
    if(array!=NULL)
    {
        for(i=0 ; i<(array->index-1) ; i++)
        {
            printf("%d ",array->*arr[i]);  /*  */
        }
    }
    return;
}



void destroy(Array_t* array)
{
    int i=0;
    for(i=0 ; i<(array->index) ; i++)	/* */
    {
	free(array->arr[i];
    }
    if(array!=NULL){
        free(array->arr);
        free(array);
    }
    return;
}
