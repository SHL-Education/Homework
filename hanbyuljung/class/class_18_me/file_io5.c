#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>


int main(void)
{

	int filedes;
	off_t newpos;

	filedes = open("data1.txt", O_RDONLY);
	// lseek 는 파일의 사이즈를 나타냄.
	// filedes 에 있는 주소가 가지고 있는 정보를 0 부터 seek_end 끝까지 사이즈를 보여줌
	newpos = lseek(filedes, (off_t)0, SEEK_END);
	printf("file size :%ld", newpos);
}

