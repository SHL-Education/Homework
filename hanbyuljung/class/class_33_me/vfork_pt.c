#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<linux/unistd.h>

int main(void)
{
	int pid;

	printf("before vfork \n \n");

	if((pid = vfork()) <0) {
		printf("fork error \n");
		exit(-2);
	}
	else if(pid == 0){
		printf("TGID(%d), PID(%d) : Child\n", getpid(), syscall(__NR_gettid));
		_exit(0);
	}
	else{
		printf("TGID(%d),PID(%d) : Parent \n", getpid(), syscall(__NR_gettid));
	}
	printf("after vfork \n\n");
	return 0;
}

