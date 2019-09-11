#include "wqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define QUEUESIZE 7
#define PRODUCERS 3
#define CONSUMERS 4
#define MESSAGES 5

typedef struct producers producers_t;
typedef struct consumers consumers_t;

producers_t* createProducers();
void joinProducers(producers_t* prod);
void* producerFunc(void* arg);

consumers_t* createConsumers();
void joinConsumers(consumers_t* prod);
void* consumerFunc(void* arg);

wqueue* pcQueue;
wqueue* cpQueue;

int main()
{
	pcQueue=createWqueue(QUEUESIZE);
	cpQueue=createWqueue(QUEUESIZE);
	createProducers(pcQueue);
	createConsumers(cpQueue);/*
	joinProducers();
	killConsumers();
	joinConsumers(consumers);*/
	destroyWqueue(pcQueue);
	destroyWqueue(cpQueue);

	return 0;
}

/******************************************************/

struct producers
{
      pthread_t thread[PRODUCERS*MESSAGES];
      unsigned int threadNumber[PRODUCERS*MESSAGES];
};

producers_t* createProducers(wqueue* pcQueue)
{
      producers_t* prod=malloc(sizeof(producers_t));
      int i=0;
      unsigned int arg=0;
      
      for(i=0 ; i<PRODUCERS ; i++)
      {
            prod->threadNumber[i]=i;
            arg=prod->threadNumber[i];
            pthread_create(&(prod->thread[i]),NULL,producerFunc,&arg);
      }

      return prod;
}

void joinProducers(producers_t* prod)
{
      int i=0;

      for(i=0 ; i<PRODUCERS ; i++)
      {
            pthread_join(prod->thread[i],NULL);
      }
      free(prod);

      return;
}

void* producerFunc(void* arg)
{
      unsigned int threadNumber=*(unsigned int*)arg;
      char* value;
      int i=0;

      for(i=0 ; i<MESSAGES ; i++)
      {
            value="izhak";
            writeToQueue(pcQueue,value);
            printf("Producer %u added %s !\n",threadNumber,value);
            pthread_exit(0);
      }

      return;
}

/**************************************************************/

struct consumers
{
      pthread_t thread[CONSUMERS*MESSAGES];
      unsigned int threadNumber[CONSUMERS*MESSAGES];
};

consumers_t* createConsumers(wqueue* cpQueue)
{
      consumers_t* cons=malloc(sizeof(consumers_t));
      int i=0;
      unsigned int arg=0;

      for(i=0 ; i<CONSUMERS ; i++)
      {
            cons->threadNumber[i]=i;
            arg=cons->threadNumber[i];
            pthread_create(&(cons->thread[i]),NULL,consumerFunc,&arg);
      }

      return cons;
}

void joinConsumers(consumers_t* cons)
{
      int i=0;

      for(i=0 ; i<CONSUMERS ; i++)
      {
            pthread_join(cons->thread[i],NULL);
      }
      free(cons);

      return;
}

void* consumerFunc(void* arg)
{
      unsigned int threadNumber=*(unsigned int*)arg;
      void** value;
      int i=0;

      for(i=0 ; i<CONSUMERS ; i++)
      {
            readFromQueue(cpQueue,value);
            printf("Consumer %u read successfully !\n",threadNumber);
            pthread_exit(0);
      }

      return NULL;
}