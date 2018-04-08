#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>

// 
jmp_buf env;

int test(void)
{
	// 1은 리턴값을 말하는 것이다.
	longjmp(env,1);
	return 1;
}
void test1(void)
{
	longjmp(env,2);
}

int main(void)
{
	int ret;
	int res;
	//setjmp 를 아무것도 안했을 때는 무조건 0이다.
	// env가 레이블의 위치를 가지고 있다.
	// setjmp 를 하면 레이블이 생긴다.
	//if((ret = setjmp(env)) == 0)
	if((ret = setjmp(env))==0){
		printf("this\n");
		test();
	}
	else if(ret == 1){
		printf("second\n");
		test1();
	}
	else if(ret == 2){
		printf("goto label\n");
		goto letme;
	}
	else
		printf("error\n");
// letme 가 레이블이다.
letme:
	// see가 longjmp
	goto see;


	return 0;
see:
	printf("error!!\n");
}

