#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>

int main(int argc, char **argv)
{
	int fd = open(argv[1],O_RDONLY);
	int line = 0;
	int word = 0;
	int flag = 0;
	int cnt = 0;
	
	char ch;
	if(argc !=2)
	{
		printf("You need I more parameter\n");
		printf("Usage: mywc filename\n");
		exit(-1);
	}

	if((fd = open(argv[1],O_RDONLY))<0)
	{
		perror("open()");
		exit(-1);
	}
	// while 문에는 1byte를 읽으니까 무언가 들어있으면 1 또는  없으면 0이 나온다
	while(read(fd,&ch,1))
	{
		cnt++;
		if(ch == '\n')
			line ++;
		if(ch != '\n' && ch != '\t' && ch != ' ')
		{
			if(flag == 0)
			{
				word++;
				flag = 1;
			}
		}else
		{
			flag = 0;
		}
	}
	close(fd);
	printf("%d %d %d %s\n",line, word, cnt, argv[1]);
	return 0;
}

	
