#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc , char **argv)
{
	int fd, ret;
	ssize_t nread;
	char buf[1024];

	fd = open(argv[1], O_WRONLY | O_CREAT ,0644);
	ret = read(0, buf,sizeof(buf));
	write(1, buf, ret);
	close(fd);

	return 0;
}




