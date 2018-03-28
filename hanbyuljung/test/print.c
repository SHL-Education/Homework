#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc , char **argv)
{
	int fd, ret;
	ssize_t nread;
	char buf[1024];
	
	fd = open(argv[1], O_WRONLY | O_CREAT |O_TRUNC, 0644);
	ret = read(0, buf, sizeof(buf));
	write(fd, buf, ret);
	close(fd);
	return 0;
}
