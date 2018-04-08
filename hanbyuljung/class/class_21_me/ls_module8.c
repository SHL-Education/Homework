#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<pwd.h>
#include<grp.h>

int main(int argc,char **argv)
{
	struct stat buf;
	struct passwd *pw;
	struct group *gr;
	char ch;
	char perm[11] = "----------";
	char rwx[4] = "rwx";
	int i;
	stat(argv[1],&buf);

	if(S_ISDIR(buf.st_mode))
		ch= 'd';
	if(S_ISREG(buf.st_mode))
		ch= '-';
	if(S_ISFIFO(buf.st_mode))
		ch= 'p';
	if(S_ISLNK(buf.st_mode))
		ch= 'i';
	if(S_ISSOCK(buf.st_mode))
		ch= 's';
	if(S_ISCHR(buf.st_mode))
		ch= 'c';
	if(S_ISBLK(buf.st_mode))
		ch= 'b';
	printf("%c\n",ch);
	for(i = 0; i<9;i++)
		if((buf.st_mode >>(8-i))&1)
			perm[i+1] =rwx[i%3];
	printf("%s ",perm);
	printf("%lu ",buf.st_nlink);
	pw = getpwuid(buf.st_uid);
	printf("%s ",pw->pw_name);
	gr = getgrgid(buf.st_gid);
	printf("%s ",gr->gr_name);
	return 0;
}
