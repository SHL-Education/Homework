#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
void read_l(char *name);

// R 일 때 이다.
void recursive_dir(char *dname, char **argv)
{
	struct dirent *p;
	struct stat buf;
	DIR *dp;
	chdir(dname);
	dp = opendir(".");
	printf("\t%s:\n",dname);
	while(p = readdir(dp)){
	
		if(argv[0] == 'l' || argv[1] == 'l' ||argv[2] == 'l')
			read_l(p->d_name);
		else
 			printf("%s\n",p->d_name);


	}
	rewinddir(dp); // 되감기 한다. 포인터의 위치를 맨앞으로 가져다 준다.
	while(p = readdir(dp))
	{
		stat(p->d_name, &buf);
		if(S_ISDIR(buf.st_mode))
			if(strcmp(p->d_name,".") && strcmp(p->d_name,".."))
			// 0일때 돌아가는거니 둘다 아닐 때만 리컬시브로 들어가란 뜻이다.
				recursive_dir(p->d_name, argv);
	}
	// 만약에 chdir 하기전에 마지막이.이면 상위로 가면 안되니까 if로 .이 아닐때만.
	// <시험 문제> 상위돌다가 바꿔야하는 프로그램.
	chdir("..");
	closedir(dp);
}

// l 일 때 이다.
void read_l(char *name)
{
	int i;
	char perm[11]="----------";
	char rwx[4] ="rwx";
	char sst[4] ="sst";
	char *arr="alRi";
	struct stat buf;
	struct passwd *pw;
	struct group *gr;
	struct tm *tm;

	stat(name,&buf);
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
	printf("%2lu ",buf.st_nlink);
	pw = getpwuid(buf.st_uid);
	printf("%3s ",pw->pw_name);
	gr = getgrgid(buf.st_gid);
	printf("%3s ",gr->gr_name);
	printf("%5lu ", buf.st_size);
	tm = localtime(&buf.st_mtime);
	printf("%5d -> %02d-%02d %02d:%02d ",
			tm->tm_year + 1900, tm->tm_mon +1,tm->tm_mday, tm->tm_hour, tm->tm_min);
	printf("%3s",name);
	printf("\n");
}

void ls_program(int flag,int argc, char **argv)
{
	int cmd, i=0, x=1;
	char ch ;
	char arr[] = "alRi\0";
	struct dirent *p;
	struct stat buf;
	
	DIR *dp;
	dp = opendir(".");
	stat(argv[1],&buf);
	
	while((cmd = getopt(argc, argv, arr))> 0)	
	{
		while(p=readdir(dp))
		{
			switch(cmd)
			{
				case'a':
					flag |= 1<<0;
					printf("%-14s", p->d_name);
					if((i+1)%5==0)
						printf("\n");
					i++;

					break;
				case'l':
					flag |= 1<<1;
					read_l((p->d_name));
					break;
				case'R':
					flag |= 1<<2;
					recursive_dir(".",argv);
					goto a;
					break;
				default:
					printf("unknown iption\n");
			}	
			if(cmd != 'a')
			{
				if(p->d_name[0] == '.')
					continue;
				if(cmd != 'l' && (i+1)%5==0 && cmd != 'R' )
					printf("\n");
				i++;				
			}
			
		}
		a:
		printf("\n");
		closedir(dp);
	}
}


int check_flag(int flag)
{
	int i, tmp = flag;

	for(i = 0; i < 7; i++)
	{
		switch(tmp & (1 << i))
		{
			case 1:
				printf("a\n");					
				break;
			case 2:
				printf("l\n");
				break;
			case 4:
				printf("R\n");
				break;
			case 8:
				printf("i\n");
				break;
			case 16:
				printf("E\n");
				break;
			case 32:
				printf("F\n");
				break;
			case 64:
				printf("G\n");
				break;
		}
	}
}

int main(int argc, char **argv)
{

	struct stat buf;
	struct dirent *p;

	DIR *dp;
	int cmd, i=0, x=1;
	int flag=0;
	char ch ;
	char arr[] = "alRi";

	dp = opendir(".");
	stat(argv[1],&buf);
	ls_program(flag, argc, argv);
	check_flag(flag);

	
	return 0;
}
