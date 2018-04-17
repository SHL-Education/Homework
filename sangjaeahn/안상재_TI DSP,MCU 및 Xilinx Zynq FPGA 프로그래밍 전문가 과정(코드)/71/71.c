#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define BUF_SIZE 1024

int main(void)
{
	int fdin, fdout, nread, nwrite, cnt=0, count=0, i=0, newpos;
	char buf[BUF_SIZE]= {0}, ch;	

	fdin = open("input.txt", O_RDWR|0644);
	fdout = open("result.txt", O_WRONLY|O_CREAT|O_TRUNC,0644);
	
	while(1)
	{
		nread = read(fdin, &ch, 1);

		if(ch == '\n')
		{
			count++;
		}
		
		cnt++;

		if(count==5)
		{
			newpos = lseek(fdin, (off_t)0, SEEK_SET);
			nread = read(fdin, buf, cnt);			
			nwrite = write(fdout, buf, cnt);
			cnt = 0;
			break;
		}			
		else if(count==10) 
		{		
			newpos = lseek(fdin, (off_t)cnt, SEEK_SET);
			nread = read(fdin, buf, cnt);			
			nwrite = write(fdout, buf, cnt);
			cnt = 0;
			break;	
		}
	}

	close(fdin);
	close(fdout);

	return 0;
}
