#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main(void)
{
	FILE *fp  =  fopen("mycmp.c","r");
	char buf[1024] = "\n";
	int ret;
	while(ret = fread(buf, 1, sizeof(buf),fp))
	{
		usleep(1000000);
		fwrite(buf, 1, ret,stdout);
	}
	fclose(fp);
	return 0;
}
