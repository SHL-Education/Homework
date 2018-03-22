#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char **argv)
{
	int cmd;
	while((cmd = getopt(argc, argv,"ab"))> 0)
	{
		switch(cmd)
		{
			case'a':
				printf("a option\n");
				break;
			case'b':
				printf("b option\n");
				break;
			default:
				printf("unknown iption\n");
		}
	}
	return 0;
}
