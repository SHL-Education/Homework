#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(void)
{
	int fdin, fdout;
	ssize_t nread;
	char buf[1024];

	fdin = open("temp1.txt",O_RDONLY);
	fdout = open("temp2.txt",O_WRONLY |O_CREAT |O_TRUNC, 0644);
	// read 에서 읽어낸 값이 반환 되어 나온다. 읽은 갯수가 되겠다.
	while((nread = read(fdin, buf, 1024))>0)
	{

		if(write(fdout,buf, nread) <nread)
		{
				close(fdin);
				close(fdout);
		}
	}
	close(fdin);
	close(fdout);
	return 0;
	
}
