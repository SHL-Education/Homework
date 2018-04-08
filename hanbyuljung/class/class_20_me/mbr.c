#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int i;
	char ch = 'a';
	int fd  = open(argv[1], O_WRONLY | O_CREAT |O_TRUNC, 0644);
	lseek(fd,512 -1, SEEK_SET);
	write(fd, &ch, 1);
	close(fd);
	return 0;
}
