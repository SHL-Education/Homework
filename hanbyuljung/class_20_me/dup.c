#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(void)
{	
	int fd;
	//fd 는 3이다.
	fd = open("a.txt",	O_WRONLY|O_CREAT|O_TRUNC,0644);
	close(1);
	dup(fd);
	printf("출력될까 ? \n");
	
	return 0;
}
