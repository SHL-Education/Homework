#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>

void term_status(int status)
{
	if(WIFEXITED(status))
		printf("(exit)status : 0x%x\n", WEXITSTATUS(stauts));
	else if(WTERMSIG(status))
		printf("(signal)status : 0x%x, %s\n",
				status & 0x7f, WCOREDUMP(status) ? "core dumped":"");
}
int main(void)
{
	pid_t pid;
	int status;
	if((pid = fork())>0)
	{
		wait(&status);
		term_status(status);
	}
	else if(pid == 0)
		abort();
	else
	{
		perror("fork()");
		exit(-1);
	}
	return 0;
}

