#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main(void)
{
	int fd, ret;
	char buf[1024];
	fd = open("myfifo",O_RDWR);
	fcntl(0, F_SETFL, O_NONBLOCK);
	fcntl(fd, F_SETFL, O_NONBLOCK);
	for(;;)
	{
		if((ret = read(0,buf, sizeof(buf)))>0)
		{
			buf[ret -1]=0;
			printf("Keyboard Inpr :[%s]\n",buf);
		}
		if((ret = read(fd , buf , sizeof(buf)))>0)
		{
			buf[ret-1] = 0;
			printf("Pipe Input :[%s]\n",buf);
		}
	}
	close(fd);
	return 0;
}
