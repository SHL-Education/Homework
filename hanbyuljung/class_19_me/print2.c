// 입력 받을것을 그대로 화면에 출력하기

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char **argv)
{
	int ref;
	int fd;
	char buf[1024];

	//fd = open(argc[1], O_CREAT |O_RWONLY, 0644);
	ref = read(0,buf,1024);
	write(1, buf, ref);


	return 0;
}
