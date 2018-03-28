#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>
#include<fcntl.h>

jmp_buf env;

void test(void)
{
	int flag= -1;
	if(flag <0)
		// jmp를 하면 돌아 오지않는다.
		longjmp(env,1);
	printf("call test(\n");

}

int main(void)
{
	int ret;
	if((ret = setjmp(env)) == 0)
		test();
	else if(ret >0)
		printf("error\n");
	return 0;
}
