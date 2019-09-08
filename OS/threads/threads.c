#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>

void* function1();
void* function2();

void* function1()
{
	int i=0;
	for(i=0 ; i<5 ; i++)
	{
		sleep(2);
		printf("1\n");
	}

	return;
}

void* function2()
{
	int i=0;
	for(i=0 ; i<3 ; i++)
	{
		sleep(3);
		printf("2\n");
	}

	return;
}

int pthreadCreate()
{
	pthread_t temp1, temp2;
	int one=pthread_create(&temp1,NULL,function1,NULL);
	int two=pthread_create(&temp2,NULL,function2,NULL);

	if(one || two)
	{
		printf("ERROR!\n");

		return -1;
	}
	pthread_join(temp1,NULL);
	pthread_join(temp2,NULL);

	return 0;
}

int main()
{
	pthreadCreate();

	return 0;
}
