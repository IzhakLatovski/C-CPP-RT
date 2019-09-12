#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

void* function1();
void* function2();
void* function3();

sem_t coin[3];

int main()
{
	pthread_t array[3];
	
	sem_init(&coin[0],0,1);
	sem_init(&coin[1],0,0);
	sem_init(&coin[2],0,0);

	pthread_create(&array[0],NULL,function1,NULL);
	pthread_create(&array[1],NULL,function2,NULL);
	pthread_create(&array[2],NULL,function3,NULL);
	
	pthread_join(array[0],NULL);
	pthread_join(array[1],NULL);
	pthread_join(array[2],NULL);

	sem_destroy(&coin[0]);
	sem_destroy(&coin[1]);
	sem_destroy(&coin[2]);

	return 0;
}

void* function1()
{
	while(1)
	{
		sem_wait(&coin[0]);
		printf("1");
		sem_post(&coin[1]);
	}
}

void* function2()
{
	while(1)
	{
		sem_wait(&coin[1]);
		printf("2");
		sem_post(&coin[2]);
	}
}

void* function3()
{
	while(1)
	{
		sem_wait(&coin[2]);
		printf("3");
		sem_post(&coin[0]);
	}
}