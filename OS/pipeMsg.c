#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pipe1[2];
    char buffer[64];
    pid_t pid;
    char fatherMessage[]="Hi son!\n";
    char sonMessage[]="BYE!!!!\n";

    if(pipe(pipe1)==-1)
    {
    	printf("No pipe made\n");
		return -1;
    }

    pid=fork();

    if(pid<0)
    {
		printf("No fork made\n");
		return -2;
    }

    else if(pid>0)  /*father*/
    {
        write(pipe1[1],fatherMessage,64);
        wait(&pid);
        read(pipe1[0],buffer,64);
        printf("%s", buffer);            
    }
    else            /*son*/
    {
        read(pipe1[0],buffer,64);
        printf("%s",buffer);
        write(pipe1[1],sonMessage,64);       
    }

    return 0;
}
