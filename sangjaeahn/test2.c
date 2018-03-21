#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char buff[1024];
	fd = open("a.txt", O_RDONLY);
	close(0);
	dup(fd);	// 0(표준입력파일) 을 fd에 복사함.
	gets(buff);	// 0번 파일 로부터 데이터를 입력을 받아서 buff에 저장함.
	
	printf("출력될까?\n");
	return 0;
}
