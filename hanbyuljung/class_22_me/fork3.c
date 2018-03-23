#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>


int main(void)
{

	printf("자식 나오라\n");
	pid_t pid;
	// 자식(분신1...) 프로세스를 생성해서 그 값을 반환한다.
	// 프로세스가 두개이다. 현재 나와 그리고 자식 프로세스.
	// 원래 실행 하고 복사한거 실행하고.
	// 그래서 두번 실행 한것처럼 보인다. fork는 복사한 것을 한번더 프로세스로 만들어
	// 실행하니까 task_struct 가 2개가 된거다.
	// fork 라는 선언이 있는  위치 줄에서 부터 복사가 된다.
	pid = fork();
	if(pid>0)
		// getpid() 현재 자신의 프로세스를 반환한다.
		printf("paretnt : pid = %d , cpid = %d\n", getpid(),pid);
	else if(pid == 0)
		printf("child : pid = %d, cpid = %d\n", getpid(),pid);
	else
	{
		perror("fork()");
		exit(-1);
	}
	return 0;
}

