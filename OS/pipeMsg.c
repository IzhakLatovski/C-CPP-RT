#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


int main()
{
	pid_t pid=0;
	int p[2];
	char fatherMsg[]="Hello son!\n";
	char sonMsg[]="BYE!!!!!\n";
	char buffer[100];


	if(pipe(p)==-1)
	{
		printf("No pipe made\n");
	}

	if(pid=fork()<0)
	{
		printf("No fork made\n");
	}

	if(pid>0)			/* PARENT */
	{
		write(p[1],fatherMsg,40);
		wait(&pid);
		read(p[0],buffer,40);
		printf("-----%s\n",buffer);
	}
	else				/* SON */
	{
		read(p[0],buffer,40);
		printf("%s\n888888888888888888888",buffer);
		write(p[1],sonMsg,40);
	}

	close(p[1]);
	close(p[0]);

	return 0;
}