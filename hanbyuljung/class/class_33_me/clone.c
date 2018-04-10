#define _GNU_SOURCE // 맨꼭대기에 있어야함.

#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<sched.h>


int g =2 ;

int sub_func(void *arg)
{
	g ++;
	printf("PID(%d) : Child g = %d \n", getpid(), g);
	sleep(2);

	return 0;
}

int main(void)
{
	int pid;
	int child_stack[4096];
	int i = 3;
	printf("PID(%d) : Parent g = %d, i = %d \n", getpid(), g,i);
	clone (sub_func, (void*)(child_stack +4095), CLONE_VM | CLONE_THREAD |CLONE_SIGHAND, NULL);
	sleep(1);
	printf("PID(%d) : Parent g= %d, i= %d \n", getpid(), g, i);
	return 0;
}
		
