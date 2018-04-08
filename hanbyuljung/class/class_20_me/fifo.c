#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(void)
{
	int fd, ret;
	char buf[1024];
	//mkfifo("myfifo");
	fd = open("myfifo",O_RDWR);
	for(;;)
	{
		ret = read( 0, buf, sizeof(buf));
		buf[ret -1]=0;
		printf("Keyboard Input : [%s]\n",buf);

		read( fd, buf, sizeof(buf));
		buf[ret-1]=0;
		printf("Pipe Input : [%s]\n",buf);
	}
	return 0;
}
