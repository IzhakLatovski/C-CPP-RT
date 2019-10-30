#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void watchDog()
{
	pid_t pid;
	int returnStatus;

	while(1)
	{
		pid=fork();
/*fork FAILED*/		
		if(pid<0)
		{
			printf("Fork failed.\n");
		}
/*PARENT code*/
		else if(pid>0)
		{
			waitpid(pid,&returnStatus,0);
		/*if the child ended NOT NORMALLY*/
			if(!WIFEXITED(returnStatus))
			{
				printf("Child proccess died NOT normally, restart.\n");
				pid=fork();
			}
		/*if the child ended NORMALLY*/
			else
			{
				printf("Child proccess died normally, continue.\n");
				break;
			}
		}
/*CHILD code example*/
		else
		{
			execlp("/bin/ls","/bin/ls",-l,NULL);
		}
	}
}