#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>

// 
jmp_buf env;

void test(void)
{
	// 1은 리턴값을 말하는 것이다.
	longjmp(env, 1);
}

int main(void)
{
	int ret;
	
	//setjmp 를 아무것도 안했을 때는 무조건 0이다.
	// env가 레이블의 위치를 가지고 있다.
	//if((ret = setjmp(env)) == 0)
	if((ret = setjmp(env))==0){
		printf("this\n");
		test();
	}
	else if(ret>0)
		printf("error\n");
	return 0;
}
