#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>


#define ERROR	-1

int main(void)
{

	int filedes;
	char pathname[] ="temp.txt";

	// O_EXCL 이 없으면 새로 만들 때 이름이 같으면 덮어 쓰게 된다.
	if((filedes = open(pathname, O_CREAT | O_RDWR |O_EXCL, 0644))== ERROR)
	{
		printf("Flie Open Error!\n");
		exit(1);
	}
		printf("fd = %d\n",filedes);
	close(filedes);
	
	return 0;
}
