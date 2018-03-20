#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int i;
	char buf[1024] = {0};
	int in, out, nread;

	if(argc != 3)
	{
		printf("인자 입력 3 개 하라고!\n");
		exit(-1);
	}

	for(i = 0; i < argc; i++)
	{
		printf("당신이 입력한 인자는 = %s\n", argv[i]);
	}

	in = open(argv[1], O_RDONLY);
	out = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC);

	while((nread = read(in, buf, 1024)) > 0)
	{
		if(write(out, buf, nread) < nread)
		{
			close(in);
			close(out);
			printf("비정상 종료\n");
			exit(-1);
		}
	}

	close(in);
	close(out);
	printf("정상 종료\n");

	return 0;
}
