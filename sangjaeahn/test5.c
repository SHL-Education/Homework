#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	int fd,ret;
	char buf[1024];
	fd = open("myfifo", O_RDWR);
	fcntl(0, F_SETFL, O_NONBLOCK);	
	fcntl(fd, F_SETFL, O_NONBLOCK);
	
	for(;;)
	{
		if((ret = read(0,buf,sizeof(buf))) > 0)
		{
			buf[ret-1] = 0;
			printf("Keyboard Input : [%s]\n", buf);
		}
		if((ret = read(fd, buf, sizeof(buf))) > 0)
		{
			buf[ret - 1] = 0;
			printf("Pipe Input : [%s]\n", buf);
		}
	}

	close(fd);
	return 0;
}

/*
int fcntl(int fd, int cmd, long arg) 
-> fd : 제어한 파일의 식별자
-> cmd : 동작지정

fcntl(fd, F_SETFL, O_NONBLOCK);
-> F_SETFL : 파일 상태 플래그를 설정한다.
-> O_NONBLOCK : nonblocking상태로 설정함.


=> blocking 과 달리 nonblocking은 파일의 읽고 쓰는 것을 기다리지 않는다.(유연성을 확보함.)
*/
