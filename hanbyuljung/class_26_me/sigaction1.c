#include<stdio.h>
#include<signal.h>
#include<unistd.h>

struct sigaction act_new;
struct sigaction act_old;

struct sigaction act_old2;

// 시그널의 동작을 처리하는 함수
void sigint_handler(int signo)
{
	
	printf("Ctrl +C\n");
	// 컨트롤 c를 눌렀을때 시그널이 날라옴 그때 한번더 누르면 꺼진다.
	printf("If you push it one more time then exit\n");
	// 
	sigaction(SIGINT , &act_old,&act_old2);
}

int main(void)
{
	// 시그널 두번째 인자에 행동을 등록하는것이다.
	act_new.sa_handler = sigint_handler;
	// 시그널을 막으려면 ignore했는데 
	// 이것도 특정 시그널을 
	// empty 아무것도 막지 않겠다.?
	// 아주 중요한 것들을 할 때 시그널을 막아야 하는데 그때를 위한.
	// 시그널을 처리하는 동안 블록화할 시그널 집합의 마스크
	sigemptyset(&act_new.sa_mask);

	//시그널은 이전 엑트를 보냈다.
	// '&' 가 들어있고 주소, 포인터를 전달한 것이다.
	// 무언가 주소를 통해서 값이 변경 시킨다는 것을 생각할 수 있다.
	// 포인터를 쓰면 함수는 원래 하나를 처리하는데 여러개를 처리 할 수 있다.
	// act_old 이전에 등록했던 시그널을 받아오는것.

	sigaction(SIGINT, &act_new, &act_old);
	pause();
	//sigaction(SIGINT, &act_new,&act_old2);
	//pause();
	//sigaction(SIGINT , &act_old2, NULL);
//	pause();
//	sigaction(SIGINT , &act_old, NULL);
	while(1)
	{
		printf("sigaction test\n");
		sleep(1);
	}
	return 0;
}
