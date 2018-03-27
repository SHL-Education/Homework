#include<stdio.h>
#include<unistd.h>

int main(void)
{
	int status;
	pid_t pid;
	char *argv[] = {"./newpgm", "newpgm", "one", "two",0};
	char *env[] = { "name = OS_Hacker", "age=20", 0};
	if ((pid = fork())>0)
	{
		wait(&status);
		printf("prompt > \n");
	}
	else if(pid == 0)
		execve("./newpgm", argv , env);
	return 0;
}
