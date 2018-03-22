#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd;
	fd = open("a.txt", O_WRONLY|O_CREAT|O_TRUNC,0644);	// 읽기전용|파일생성|기존파일삭제 옵션으로 a.txt파일을 open함.
	close(1);	// 표준출력장치를 close함.
	dup(fd);	// fd에 close한 파일 번호를 저장함.(fd=1 이 됨.)
	printf("출력 될까?\n");	// "출력 될까?\n" 를 fd파일
	return 0;
}

/* dup() 함수
close(fd1)

dup(fd2) 

-> dup함수 바로 전에 종료한 fd1을 fd2에 복사함.
*/

