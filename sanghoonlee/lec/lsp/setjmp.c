#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf env1;
jmp_buf env2;

void test1(void)
{
	longjmp(env1, 1);
}

void test2(void)
{
	longjmp(env1, 2);
}

void test3(void)
{
	longjmp(env2, 1);
}

int main(void)
{
	int ret;
	if((ret = setjmp(env1)) == 0)
	{
		printf("this\n");
		test1();
	}
	else if(ret == 1)
	{
		printf("1\n");
		test2();
	}
	else if(ret == 2)
		printf("2\n");
	else
	{
		printf("goto letsgo label\n");
		goto letsgo;
	}

	if((ret = setjmp(env2)) == 0)
	{
		printf("second label\n");
		test3();
	}
	else
		longjmp(env1, 3);
letsgo:
		goto err;

	return 0;

err:
	printf("Error!!!\n");
	exit(-1);
}
