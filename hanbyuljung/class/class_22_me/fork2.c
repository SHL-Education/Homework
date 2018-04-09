#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

int main(void)
{
	//pid_t 는 int 형이다.
	pid_t pid;
	// 자식의 pid 값을 반환한다.
	pid =fork();
	
	if(pid>0)
		printf("parent\n");
	else if(pid==0)
		printf("child\n");
	// 이도 저도 아니면 에러.
	else
	{
		perror("fork()");
		exit(-1);
	}
	return 0;
}

