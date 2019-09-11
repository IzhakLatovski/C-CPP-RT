#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "consumer.h"
#include "wqueue.h"

#define QUEUESIZE 7
#define PRODUCERS 3
#define CONSUMERS 4
#define MESSAGES 5

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