#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int my_system(char *cmd){

	pid_t pid;
	int status;
	// sh = 배쉬 쉘, -c 해당 커맨드를 실행해라, 커맨드 하나, 0널문자로 종료)
	char *argv[]= {"sh", "-c", cmd,0};
	char *envp[]= {0};
	if((pid = fork())>0)
		wait(&status);
	else if(pid == 0)	
		execve("/bin/sh",argv,envp);
}

int main(void)
{
	my_system("date");
	printf("after\n");
	return 0;
}

