#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "producer.h"
#include "wqueue.h"

#define QUEUESIZE 7
#define PRODUCERS 3
#define CONSUMERS 4
#define MESSAGES 5

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