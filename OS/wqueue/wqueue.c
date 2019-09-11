#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include "wqueue.h"

#define QUEUESIZE 7
#define PRODUCERS 3
#define CONSUMERS 4
#define MESSAGES 5

struct wqueue
{
	void** array;
	unsigned int head;
	unsigned int tail;
	sem_t semEmpty;
	sem_t semFull;
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
	sem_init(&(newWqueue->semEmpty),0,sizeOfQueue);
	sem_init(&(newWqueue->semFull),0,0);
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
		free(newWqueue->array);
		free(newWqueue);
	}
	pthread_mutex_destroy(&(newWqueue->lock));
    sem_destroy(&(newWqueue->semEmpty));
    sem_destroy(&(newWqueue->semFull));

	return 0;
}

int writeToQueue(wqueue* newWqueue, void* message)
{
	unsigned int index;

	if(newWqueue==NULL || message==NULL)
	{
		return -1;
	}
	sem_wait(&(newWqueue->semEmpty));
	pthread_mutex_lock(&(newWqueue->lock));
	index=newWqueue->tail;
	newWqueue->array[index]=message;
	newWqueue->tail=((newWqueue->tail+1)%newWqueue->size);
	newWqueue->itemsCounter++;
	pthread_mutex_unlock(&(newWqueue->lock));
	sem_post(&(newWqueue->semFull));

	return 0;
}

int readFromQueue(wqueue* newWqueue, void** message)
{
	unsigned int index;

	if(newWqueue==NULL || message==NULL)
	{
		return -1;
	}
	sem_wait(&(newWqueue->semFull));
	pthread_mutex_lock(&(newWqueue->lock));
	index=newWqueue->head;
	*message=newWqueue->array[index];
	newWqueue->head=((newWqueue->head+1)%newWqueue->size);
	newWqueue->itemsCounter--;
	pthread_mutex_unlock(&(newWqueue->lock));
	sem_post(&(newWqueue->semEmpty));

	return 0;
}

void printWqueue(wqueue* newWqueue)
{
	unsigned int i=0;

	printf("\n%uitems...Head: %u...Tail: %u\n",newWqueue->itemsCounter,newWqueue->head,newWqueue->tail);	
	for(i=0 ; i<newWqueue->size ; i++)
	{
		printf("%u: %s | ",i+1,(char*)newWqueue->array[i]);
	}
	printf("\n");

	return;
}