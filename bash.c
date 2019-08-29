#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>

#define MAX_NAME_SIZE 10

int main()
{
	char* parameters[]={"", NULL};
	pid_t pid=0;
	char fileName[MAX_NAME_SIZE];
	
	printf("\nEnter a command to execute:\n\n");	
	scanf("%s",fileName);
	
	pid=fork();

	if(pid!=0)				/*PARENT*/
	{
		waitpid(pid);
		return 0;
	}

	else					/*CHILD*/
	{
		execv(fileName,parameters);
	}

	return 0;
}