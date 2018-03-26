#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(void)
{
	pid_t pid;
	int status;
	if((pid=fork()) > 0)
	{
		wait(&status);
		printf("status : 0x%x\n",(status >>8) &0xff);
	}
	else if(pid == 0)
		exit(7);
	else
	{
		perror("fork()");
		exit(-1);
	}
	return 0;
}
