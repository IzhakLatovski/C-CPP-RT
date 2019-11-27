#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>

#define SIZE 10000

int counter=0;
/*****************************/
/**/ pthread_mutex_t lock; /**/
/*****************************/

void *myThread(void *vargp) 
{
/**********************************/
/**/ pthread_mutex_lock(&lock); /**/ 
/**********************************/
	sleep(0); 
	counter++;
	printf("%d \n",counter);
/**********************************/
/**/ pthread_mutex_unlock(&lock); /**/
/**********************************/

	return NULL; 
}

int main() 
{
	int i=0;
	pthread_t thread_id[SIZE];
/**********************************************/
/**/ if(pthread_mutex_init(&lock, NULL)!=0) /**/ 
/**********************************************/
	{
		printf("mutex init fail\n");
		return 1;
	}
	for(i=0 ; i<SIZE ; i++)
	{
		pthread_create(&thread_id[i], NULL, myThread, NULL);
	}
	for(i=0 ; i<SIZE ; i++)
	{
		pthread_join(thread_id[i], NULL); 
	}
/*************************************/
/**/ pthread_mutex_destroy(&lock); /**/ 
/*************************************/	 
	return 0; 
}