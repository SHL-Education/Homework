#include<unistd.h>
#include<stdio.h>
int main(void)
{
	int status;
	pid_t pid;
	if((pid= fork())>0)
	{
		wait(&status);
		printf("prompt >");
	}
	else if(pid == 0)
		execl("./newpgm", "newpgm","one","two", (char*)0);
	return 0;
}
