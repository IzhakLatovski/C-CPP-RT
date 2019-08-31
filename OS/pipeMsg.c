#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>

int main()
{
	pid_t pid=0;
	int pipe1[2];
	int pipe2[2];
	char fatherMsg[]="Hello son!\n";
	char sonMsg[]="BYE!!!!!\n";
	char buffer[100];

	if(pipe(pipe1)==-1)
	{
		printf("No pipe made\n");
		return -1;
	}
	if(pipe(pipe2)==-1)
	{
		printf("No pipe made\n");
		return -1;
	}

	if(pid=fork()<0)
	{
		printf("No fork made\n");
		return -2;
	}

	if(pid>0)			/* PARENT */
	{
		write(pipe1[1],fatherMsg,100);
		wait(NULL);
		read(pipe2[0],buffer,100);
		printf("-----%s\n",buffer);
	}
	else				/* SON */
	{
		read(pipe1[0],buffer,100);
		printf("%s\n888888888888888888888",buffer);
		write(pipe2[1],sonMsg,100);
	}

	return 0;
}
