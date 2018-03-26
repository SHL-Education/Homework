#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main(int argc, char **argv)
{
	int status;
	pid_t pid;
	if((pid= fork())>0)
	{
		wait(&status);
		printf("prompt >");
	}
	else if(pid == 0)
		execlp("ps",argv[1],argv[2],argv[3],NULL);
	return 0;
}

