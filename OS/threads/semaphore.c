#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h> 

#define SIZE 10000

void* function(void* sum);

sem_t coin;

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
}