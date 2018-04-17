#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	struct stat s;
	char ch;

	stat(argv[1], &s);

	if(S_ISDIR(s.st_mode))
		ch = 'd';
	if(S_ISREG(s.st_mode))
		ch = '-';
	if(S_ISFIFO(s.st_mode))
		ch = 'p';
	if(S_ISLNK(s.st_mode))
		ch = 'l';
	if(S_ISSOCK(s.st_mode))
		ch = 's';
	if(S_ISCHR(s.st_mode))
		ch = 'c';
	if(S_ISBLK(s.st_mode))
		ch = 'b';

	printf("%c\n", ch);

	return 0;
}
