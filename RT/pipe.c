#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int function()
{
	int fds[2];
	pipe(fds);
	if(!fork())
	{
		close(1);
		dup2(fds[1],1);
		close(fds[0]);
		return execlp("/bin/ls","/bin/ls",-l,NULL);
	}
	if(!fork())
	{
		close(0);
		dup2(fds[0],0);
		close(fds[1]);
		return execlp("/bin/wc","/bin/wc",-l,NULL);
	}

	/*close the parents connection to the pipe*/
	close(fds[0]);
	close(fds[1]);

	/*this is the parent*/
}