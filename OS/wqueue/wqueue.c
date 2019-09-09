#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include "wqueue.h"

#define SIZE 10

struct wqueue
{
	char** array;
	unsigned int head;
	unsigned int tail;
	sem_t semE;
	sem_t semF;
	/*mutex*/	
	unsigned int size;
	unsigned int itemsCounter;
};

wqueue* createWqueue(unsigned int sizeOfQueue)
{
	wqueue* newWqueue=(wqueue*)malloc(sizeof(wqueue));
	if(newWqueue==NULL)
	{
		return NULL;
	}
	if(sizeOfQueue<1)
	{
		return NULL;
	}
	newWqueue->array=(char**)malloc(sizeof(char*)*(sizeOfQueue));
	newWqueue->head=0;
	newWqueue->tail=0;
	newWqueue->size=sizeOfQueue;
	newWqueue->itemsCounter=0;

	return newWqueue;
}

int destroyWqueue(wqueue* newWqueue)
{
	if(newWqueue==NULL)
	{
		return -1;
	}
	if(newWqueue->array==NULL)
	{
		free(newWqueue);
		return -1;
	}
	else
	{
		free(newWqueue->array);
		free(newWqueue);
	}

	return 0;
}

int writeToQueue(wqueue* newWqueue, char* message)
{
	strcpy(newWqueue->array[0],message);
	newWqueue->tail=((newWqueue->tail+1)%newWqueue->size);
	newWqueue->itemsCounter++;

	return 0;
}

int main()
{
	int result=3;
	wqueue* temp;

	char string[]="izhak";

	temp=createWqueue(50);
	result=destroyWqueue(temp);
	printf("%d\n",result);
	printf("HEAD:%d\n",(int)temp->head);
	printf("TAIL:%d\n",(int)temp->tail);

	writeToQueue(temp,string);
/*
	printf("\n\n%s\n\n",(char*)(temp->array[0]));
*/
	printf("HEAD:%d\n",(int)temp->head);
	printf("TAIL:%d\n",(int)temp->tail);

	return 0;
}








/*
int main()
{
	int i=0, sum=0;
	pthread_t array[SIZE];
	
	sem_init(&coin,0,1);
	for(i=0 ; i<SIZE ; i++)
	{
		pthread_create(&array[i],NULL,function,&sum);
	}
	for(i=0 ; i<SIZE ; i++)
	{
		pthread_join(array[i],NULL);
	}
	sem_destroy(&coin);

	return 0;
}

void* function(void* sum)
{
	sem_wait(&coin);
	printf("My index is %d!\n",*((int*)sum));
	(*((int*)sum))++;
	sem_post(&coin);

	return;
}*/
