#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	int fd, ret;
	char buf[1024];
	mkfifo("myfifo");	// "myfifo" 파일명의 파이프 파일을 생성함.
	fd = open("myfifo", O_RDWR);	// "myfifo" 파일을 읽기/쓰기 옵션으로 open함.
	
	for(;;)	// 무한반복
	{
		ret = read(0, buf, sizeof(buf));	// 표준입력파일에서 buf크기만큼의 데이터를 buf에 저장함.
		buf[ret-1] = 0;		// buf 배열의 마지막 index값을 0으로 만듬.
		printf("Keyboard Input : [%s]\n", buf);	
		read(fd, buf, sizeof(buf));	// 파이프파일로부터 데이터를 읽어서 buf에 저장함.
		buf[ret-1] = 0;
		printf("Pipe Input : [%s]\n", buf);
	}

	return 0;
}
