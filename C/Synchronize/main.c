#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE 10000

int counter=0;
/*******************/
/**/ sem_t lock; /**/
/*******************/

void *myThread(void *vargp) 
{
/************************/
/**/ sem_wait(&lock); /**/ 
/************************/
	sleep(0); 
	counter++;
	printf("%d \n",counter);
/************************/
/**/ sem_post(&lock); /**/ 
/************************/
	
	return NULL; 
}

int main() 
{
	int i=0;
	pthread_t thread_id[SIZE];
	/******************************/
	/**/ sem_init(&lock, 0, 1); /**/ 
	/******************************/
	for(i=0 ; i<SIZE ; i++)
	{
		pthread_create(&thread_id[i], NULL, myThread, NULL);
	}
	for(i=0 ; i<SIZE ; i++)
	{
		pthread_join(thread_id[i], NULL); 
	}
	/***************************/
	/**/ sem_destroy(&lock); /**/ 
	/***************************/
	 
	return 0; 
}
