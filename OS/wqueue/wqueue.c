#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include "wqueue.h"

#define SIZE 10

struct wqueue
{
	void** array;
	unsigned int head;
	unsigned int tail;
	sem_t semWrite;
	sem_t semRead;
	pthread_mutex_t lock;
	unsigned int size;
	unsigned int itemsCounter;
};

wqueue* createWqueue(unsigned int sizeOfQueue)
{
	void** temp;
	wqueue* newWqueue=(wqueue*)malloc(sizeof(wqueue));
	if(newWqueue==NULL)
	{
		return NULL;
	}
	if(sizeOfQueue<1)
	{
		return NULL;
	}
	temp=(void**)malloc(sizeof(void*)*(sizeOfQueue));
	if(temp==NULL)
	{
		return NULL;
	}
	newWqueue->array=temp;
	newWqueue->head=0;
	newWqueue->tail=0;
	newWqueue->size=sizeOfQueue;
	newWqueue->itemsCounter=0;
	sem_init(&(newWqueue->semWrite),0,sizeOfQueue);
	sem_init(&(newWqueue->semRead),0,0);
	if(pthread_mutex_init(&(newWqueue->lock),NULL)!=0)
	{
		return NULL;
	}


	return newWqueue;
}

int destroyWqueue(wqueue* newWqueue)
{
	unsigned int i=0;

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
		for(i=0 ; i<newWqueue->size ; i++)
		{
			free(newWqueue->array[i]);
		}
		free(newWqueue->array);
		free(newWqueue);
	}

	return 0;
}

int writeToQueue(wqueue* newWqueue, void* message)
{
	unsigned int index;

	if(newWqueue==NULL || message==NULL)
	{
		return -1;
	}
	sem_wait(&(newWqueue->semWrite));
	pthread_mutex_lock(&(newWqueue->lock));
	index=newWqueue->tail;
	newWqueue->array[index]=message;
	newWqueue->tail=((newWqueue->tail+1)%newWqueue->size);
	newWqueue->itemsCounter++;
	pthread_mutex_unlock(&(newWqueue->lock));
	sem_post(&(newWqueue->semRead));

	return 0;
}

int readFromQueue(wqueue* newWqueue, void** message)
{
	unsigned int index;

	if(newWqueue==NULL || message==NULL)
	{
		return -1;
	}
	sem_wait(&(newWqueue->semRead));
	pthread_mutex_lock(&(newWqueue->lock));
	index=newWqueue->head;
	*message=newWqueue->array[index];
	newWqueue->head=((newWqueue->head+1)%newWqueue->size);
	newWqueue->itemsCounter--;
	pthread_mutex_unlock(&(newWqueue->lock));
	sem_post(&(newWqueue->semWrite));

	return 0;
}