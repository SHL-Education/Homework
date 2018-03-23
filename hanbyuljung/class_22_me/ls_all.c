#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<sys/types.h>
#include<sys/stat.h>



#define A (1<<0)
#define B (1<<1)
#define C (1<<2)
#define D (1<<3)
#define E (1<<4)
#define F (1<<5)
#define G (1<<6)

void read_perm(char *perm)
{
	int i;
	
	if(S_ISDIR(buf.st_mode))
		perm[0] = 'd';
	if(S_ISREG(buf.st_mode))
		perm[0] = '-';
	if(S_ISFIFO(buf.st_mode))
		perm[0] = 'p';
	if(S_ISSOCK(buf.st_mode))
		perm[0] = 's';
	if(S_ISCHR(buf.st_mode))
		perm[0] = 'c';
	if(S_ISLNK(buf.st_mode))
		perm[0]=  'i';
	if(S_ISBLK(buf.st_mode))
		perm[0] = 'b';
	for(i= 0; i<9; i++)
		if((buf.st_mode >>(8-i))& 1)
			perm[i+1] = rwx[i%3];
	for(i=0;i<3;i++)
		if((buf.st_mode>>(11-i))&1)
			if(perm[(i+1)*3]=='-')
				perm[(i+1)*3]=sst[i]^0x20;
			else
				perm[(i+1)*3]=sst[i];

	printf("%s ", perm);
	printf("%lu ",buf.st_nlink);
	pw = getpwuid(buf.st_uid);
	printf("%s ",pw->pw_name);
	gr = getgrgid(buf.st_gid);
	printf("%s ",gr->gr_name);
	printf("%lu ", buf.st_size);
	tm = localtime(&buf.st_mtime);
	printf("%d -> %02d-%02d %02d:%02d",
			tm->tm_year + 1900, tm->tm_mon +1,tm->tm_mday, tm->tm_hour, tm->tm_min);
	printf("\n");
}


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

	struct stat buf;
	struct dirent *p;
	struct passwd *pw;
	struct group *gr;
	struct tm *tm;
	struct dirent *p;
	DIR *dp;
	int cmd, i=0, x=1;
	char ch ;
	char perm[11]="----------";
	char rwx[4] ="rwx";
	char sst[4] ="sst";
	char *arr="alRi";
	stat(argv[1],&buf);
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
