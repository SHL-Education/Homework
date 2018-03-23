#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>


#define A (1<<0)
#define B (1<<1)
#define C (1<<2)
#define D (1<<3)
#define E (1<<4)
#define F (1<<5)
#define G (1<<6)

void check_flag(int flag)
{
	int i, tem = flag;

	switch(temp | A | B | C | D | E | F | G)
	{
		case 1:
			printf("A\n");
			break;
		case 2:
			printf("B\n");
			break;
		case 3:
			printf("C\n");
			break;
		case 4:
			printf("D\n");
			break;
		case 5:
			printf("E\n");
			break;
		case 6:
			printf("F\n");
			break;
		case 7:
			printf("G\n");
			break;
		default:
			printf("???"\n);
	}
}

int main(int argc, char **argv)
{
	DIR *dp;
	int cmd, i=0, x=1;
	struct dirent *p;
	char *arr="abcdefg";
	while((cmd = getopt(argc, argv, arr))> 0)
	{
		switch(cmd)
		{
			case'a':
				flag |= 1<<0;
				printf("a option\n");
				break;
			case'b':
				flag |= 1<<1;
				printf("b option\n");
				break;
			case'c':
				flag |= 1<<2;
				printf("c option\n");
				break;
			case'd':
				flag |= 1<<3;
				printf("d option\n");
				break;
			case'e':
				flag |= 1<<4;
				printf("e option\n");
				break;
			case'f':
				flag |= 1<<5;
				printf("f option\n");
				break;
			case'g':
				flag |= 1<<6;
				printf("g option\n");
				break;
			default:
				printf("unknown iption\n");
		}
	}
	return 0;
}
