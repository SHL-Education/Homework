#include<stdio.h>
#include<signal.h>
#include<unistd.h>

struct sigaction act_new;
struct sigaction act_old;

void sigint_handler(int signo)
{
	printf("Ctrl +C\n");
	printf("If you push it one more time then exit\n");
	sigaction(SIGINT , &act_old, NULL);
}

int main(void)
{
	// 시그널 두번째 인자에 행동을 등록하는것이다.
	act_new.sa_handler = sigint_handler;
	// 시그널을 막으려면 ignore했는데 
	// 이것도 특정 시그널을 
	// empty 아무것도 막지 않겠다.?
	// 아주 중요한 것들을 할 때 시그널을 막아야 하는데 그때를 위한.
	sigemptyset(&act_new.sa_mask);

	//시그널은 이전 엑트를 보냈다.
	// '&' 가 들어있고 주소, 포인터를 전달한 것이다.
	// 무언가 주소를 통해서 값이 변경 시킨다는 것을 생각할 수 있다.
	// 포인터를 쓰면 함수는 원래 하나를 처리하는데 여러개를 처리 할 수 있다.
	// act_old 이전에 등록했던 시그널을 받아오는것.

	sigaction(SIGINT, &act_new, &act_old);

	while(1)
	{
		printf("sigaction test\n");
		sleep(1);
	}
	return 0;
}
