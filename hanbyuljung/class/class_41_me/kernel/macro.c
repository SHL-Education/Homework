#include <stdio.h>

#define test(name)	sys_##name

void sys_fork(void)
{
	printf("This is sys_fork function by macro test(name)\n");
}

int main(void)
{
	test(fork);
	//sys_fork();
	return 0;
}
