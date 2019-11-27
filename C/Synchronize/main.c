#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define SIZE 10000
#define LOCKS_NUMBER 20

int counter=0;
/*******************************************/
/**/ pthread_mutex_t lock[LOCKS_NUMBER]; /**/
/*******************************************/

void *myThread(void *vargp) 
{
	int random_binary;
	random_binary=rand()%LOCKS_NUMBER;
/*************************************************/
/**/ pthread_mutex_lock(&lock[random_binary]); /**/ 
/*************************************************/
	sleep(0); 
	counter++;
	printf("%d \n",counter);
/***************************************************/
/**/ pthread_mutex_unlock(&lock[random_binary]); /**/
/***************************************************/

	return NULL; 
}

int main() 
{
	int i=0;
	pthread_t thread_id[SIZE];
	srand(time(0));

	for(i=0 ; i<LOCKS_NUMBER ; i++ )
	{
/*************************************************/
/**/ if(pthread_mutex_init(&lock[i], NULL)!=0) /**/ 
/*************************************************/
		{
			printf("mutex init fail\n");
			return 1;
		}
	}
	for(i=0 ; i<SIZE ; i++)
	{
		pthread_create(&thread_id[i], NULL, myThread, NULL);
	}
	for(i=0 ; i<SIZE ; i++)
	{
		pthread_join(thread_id[i], NULL); 
	}
	for(i=0 ; i<LOCKS_NUMBER ; i++ )
	{
/****************************************/
/**/ pthread_mutex_destroy(&lock[i]); /**/ 
/****************************************/
	}

	return 0; 
}