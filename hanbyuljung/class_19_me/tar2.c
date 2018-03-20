#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(void)
{
	char buff[1024];
	int fd[2];

	fd[0] = open("mytar.c", O_RDONLY);
	read(fd[0], buff, 10);
	write(1, buff,10);

	fd[1] = open("mytar.c",O_RDONLY);
	read(fd[1],buff,10);
	write(1,buff,10);
	return 0;
}
