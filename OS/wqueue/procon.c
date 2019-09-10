#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include "wqueue.h"

#define QUEUE_SIZE 10
#define PRODUCERS 5
#define MESSAGES 10
#define CONSUMERS 10


static void printWqueue(wqueue* newWqueue);

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

int main()
{
	int result=3;
	wqueue* temp;
	void** check;
	char string[]="izhak";

	check=(void**)malloc(sizeof(void*));

	temp=createWqueue(QUEUE_SIZE);

	printf("\nCREATED:");
	printWqueue(temp);

	writeToQueue(temp,string);

	printf("\n1 INSERT:");
	printWqueue(temp);

	writeToQueue(temp,"sqrt");

	printf("\n2 INSERTS:");
	printWqueue(temp);

	readFromQueue(temp,check);

	printf("\n1 DELETE:");
	printWqueue(temp);

	result=destroyWqueue(temp);

	return 0;
}

static void printWqueue(wqueue* newWqueue)
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