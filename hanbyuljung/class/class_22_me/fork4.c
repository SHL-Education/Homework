#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

int main(void)
{
	pid_t pid;
	int i;
	pid = fork();
	if(pid>0)
	{
		while(1){
			for(i = 0; i<26;i++)
			{
				printf("%c",i+'A');
				fflush(stdout);
			}
		}
	}
	else if(pid ==0)
	{
		while(1){
			for(i = 0; i<26; i++)
			{
				printf("%c", i+'a');
				fflush(stdout);
			}
		}
	}
	else
	{
		perror("fork())");
		exit(-1);
	}
	printf("\n");
	return 0;
}
