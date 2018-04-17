#include <stdio.h>
#include <signal.h>

void sig_handler(int signo)
{
	exit(0);
}

int main(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, sig_handler);
	pause();
	return 0;
}

/*
SIGINT는 'CITL + C'를 막는 신호이다. 
*/
