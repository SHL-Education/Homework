#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<linux/unistd.h>

int main(void)
{
	int pid;

	printf("before fork \n \n");

	if((pid = fork())<0){
		printf("fork error \n");
		exit(-2);
	}
	else if(pid == 0)
		printf("TGID(%ld),  PID(%ld): Child\n", getpid(), syscall(__NR_gettid));
	else
		printf("TGID(%ld), PID(%ld): Parent \n", getpid(), syscall(__NR_gettid));
	sleep(2);
	
	printf("after fork \n\n");

	return 0;
}
