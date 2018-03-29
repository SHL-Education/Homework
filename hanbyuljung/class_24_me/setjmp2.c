#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>
#include<fcntl.h>

jmp_buf env;
jmp_buf gogo;

void test(void)
{
	int flag= -1;
	if(flag <0)
		// jmp를 하면 돌아 오지않는다.
		longjmp(env,1);
	printf("call test(\n");

}
void test2(void)
{
	longjmp(gogo,2);
	printf("call test2!\n");
}

int main(void)
{
	int ret;

	if((ret = setjmp(env)) == 0)
		test();
	else if(ret >0){
		printf("error\n");

		//ret = setjmp(gogo);
		//printf("error22\n");
		//sleep(1);
		//test2();
		//longjmp(gogo,2);
	}
	//if(ret == 2){
//		printf("jump\n");
//		exit(0);
//	}
	return 0;
		
}
