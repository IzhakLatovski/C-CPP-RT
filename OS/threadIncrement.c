#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>

void* increment();

int count=0;

int main()
{
	pthread_t tid;
	int i=0;

	for(i=0 ; i<100 ; i++)
	{
		pthread_create(&tid,NULL,increment,NULL);
		pthread_join(tid,NULL);
	}
	printf("---%d---\n",count);

	return 0;
}

void* increment()
{
	count++;

	return;
}