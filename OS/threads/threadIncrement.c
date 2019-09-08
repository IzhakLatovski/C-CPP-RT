#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>

void* increment();

int count=0;

int main()
{
	int i=0;
	pthread_t array[100];

	for(i=0 ; i<100 ; i++)
	{
		pthread_create(&array[i],NULL,increment,NULL);

	}
	for(i=0 ; i<100 ; i++)
	{
		pthread_join(array[i],NULL);

	}

	printf("---%d---\n",count);

	return 0;
}

void* increment()
{
	count++;

	return;
}
