#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char **argv)
{
	int fd, ret;
	char buf[1024];
	if(argc != 2)
	{
		printf("Usage:mycat filename\n");
		exit(-1);
	}
	fd = open(argv[1],O_RDONLY);
	while(ret = read(fd,buf,sizeof(buf)))
	{
		write(1,buf,ret);
	}
	close(fd);
	return 0;
}

