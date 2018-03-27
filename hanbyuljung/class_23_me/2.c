#include <stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>

void term_status(int status)
{
	// 정상종료이다. 정상 종료 했으니가 0이 나오는데 return 이 0이기 때문이다.
	if(WIFEXITED(status))
		printf("(exit)status :0x%x\n",WEXITSTATUS(status));
	// 시그널에 맞아서 죽었다.
	// 시그널에 맞아 죽으면 core domp의 setting에 따라서 시그널 에러 번호가 뜬다.
	// 어떤 상황에 따라서 어떻게 동작 시킬지 비동기 처리 할 수 있다.
	// 어떤 상황에 따른 처리를 하고 싶을 때는 시그널로 처리해야한다.
	else if(WTERMSIG(status))
		printf("(siganl)status : 0x%x,%s\n",
				status & 0x7f, WCOREDUMP(status) ? "core dumped" :"");
}

void my_sig(int signo)
{
	int status;
	// 차일드가 시그널 상태를 보낼 때 까지 기다리는 함수이다.
	// wait는 blocking이다.
	wait(&status);
	// term_status 에 의해서 어떻게 죽었는지 확인한다.
	term_status(status);
}

int main(void)
{
	
	pid_t pid;
	int i;
	signal(SIGCHLD, my_sig);
	if((pid = fork())>0)
		for(i=0;i<10000;i++)
		{
			usleep(50000);
			printf("%d\n",i+1);
		}
	else if(pid == 0)
		sleep(5);
	else
	{
		perror("fork()");
		exit(-1);
	}
	return 0;
}
