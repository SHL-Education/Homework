#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void my_sig(int signo)
{
	printf("my_sig called\n");
}

void my_sig2(int signo)
{
	printf("my_sig2 called\n");
}
//
int main(void)
{
	void (*old_p)(int);
	void (*old_p2)(int);
	//행동지침을 실행하고(my_sig),  null 값을 반환한다. 그리고 저장을 한다.
	old_p = signal(SIGINT, my_sig); 
	pause();	
	// my_sig2를 실행하고, 이전거를 반환한다, 그리고 현재 mysig2를 저장한다. 
	old_p2 = signal(SIGINT, my_sig2); 
	pause();
	old_p2 = signal(SIGINT, old_p2); 
	//old_p2가 null값을 가지고 있어서
	//signal은 자기 자신의 한단계 전걸 리턴해 준다.
	pause();
	for(;;)
		pause();
	return 0;
}

/*
old p


*/
