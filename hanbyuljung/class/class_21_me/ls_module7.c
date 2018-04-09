#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>

int main(int argc, char **argv)
{
	struct stat buf;
	char ch;
	char perm[11] = "----------";
	char rwx[4] = "rwx";
	int i;
	stat(argv[1],&buf);
	
	if(S_ISDIR(buf.st_mode))
		perm[0] = 'd';
	if(S_ISREG(buf.st_mode))
		perm[0] = '-';
	if(S_ISFIFO(buf.st_mode))
		perm[0] = 'p';
	if(S_ISLNK(buf.st_mode))
		perm[0] = 'l';
	if(S_ISSOCK(buf.st_mode))
		perm[0] = 's';
	if(S_ISCHR(buf.st_mode))
		perm[0] = 'c';
	if(S_ISBLK(buf.st_mode))
		perm[0] = 'b';
	for(i = 0 ; i< 9; i++)
		if((buf.st_mode >> (8-i))&1)
			perm[i+1] = rwx[i%3];
	printf("%s\n",perm);
	return 0;
}
