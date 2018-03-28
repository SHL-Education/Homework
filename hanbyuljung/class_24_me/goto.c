#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<fcntl.h>


void run(void)
{
	// goto는 stack을 해제를 할 능력이 없다.
	goto err;
}

int main(void)
{
	int ret;
	char buf[1024] =" aaaabbbbcccc";
	if ((ret = read(0, buf,sizeof(buf)))>0)
		run();
	return 0;

err:
	perror("read()");
	exit(-1);
}
