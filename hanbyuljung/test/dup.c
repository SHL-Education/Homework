#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(void)
{
	int fd;
	fd = open("a.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// 기본 출력인 모니터를 닫는다.
	close(1);
	// 파일 스크립터를 복사하면 모니터의 출력이 될부분이 모니터창에 들어간다.
	// close를 하면 다시 열수가 없다.
	dup(fd);
	printf("출력될까?\n");

	return 0;
}
