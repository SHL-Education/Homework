#include<signal.h>
#include<stdio.h>

int main(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGKILL, SIG_IGN);
	// 시그널을 받을 때까지 기다리는 함수.
	pause();
	return 0;
}
