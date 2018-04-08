#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char **argv)
{
	int fdin, fdout;
	ssize_t nread;
	char buf[2048];
	int i;


/*
	if(argc != 3)
	{
		printf("인자를 입력 3개 하시오\n");
		exit(-1);
	}
	for(i = 0 ; i<argc; i++)
	{
		printf("당신이 입력한 인자는 = %s\n", argv[i]);
	}
*/
	fdin = open(argv[1],O_RDONLY);
	fdout = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0644);

	while((nread = read(fdin, buf, 1024))>0)
	{
		if(write(fdout, buf, nread)< nread)
		{
			close(fdin);
			close(fdout);
		}
	}
	close(fdin);
	close(fdout);
	
	return 0;
}
