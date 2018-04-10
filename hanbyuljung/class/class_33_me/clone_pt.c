#define _GNU_SOURCE
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<linux/unistd.h>
#include<sched.h>

int sub_func_b(void*arg)
{
	printf("TGID(%d), PID(%d):Child \n", getpid(), syscall(__NR_gettid));
	sleep(2);
	return 0;
}

int main(void)
{
	int pid;
	int child_a_stack[4096], child_b_stack[4096];

	printf("before clone \n \n");
	printf("TGID(%d), PID(%d) : Parent \n", getpid(), syscall(__NR_gettid));

	clone(sub_func_b, (void*)(child_a_stack+4095), CLONE_CHILD_CLEARTID |CLONE_CHILD_SETTID, NULL);
	clone(sub_func_b, (void*)(child_b_stack+4095), CLONE_VM |CLONE_THREAD |CLONE_THREAD |CLONE_SIGHAND, NULL);
	sleep(1);

	printf("after clone \n\n");
	return 0;
}


