#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int i;	
	char ch = 'z';
	int fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC,0644);

	lseek(fd, 512-1, SEEK_SET);	// fd파일의 SEEK_SET(처음)위치에서 512-1 만큼의 오프셋을 시키고 파일 포인터를 위치시킴. 
	write(fd,&ch,1);	// fd의 현재 파일포인터에 ch값을 1바이트 write함.
	close(fd);		// fd 종료
	
	return 0;
}
