#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	DIR *dp;
	int i=0, cmd;
	struct dirent *p;
	cmd = getopt(argc,argv, "a");
	printf("%c\n",cmd);
	dp = opendir(".");
	
	while(p = readdir(dp))
	{
		if(cmd != 'a')	// a 옵션이 있으면 모든 파일 출력
		{
			if(p->d_name[0] == '.')
				continue;
		}	
		printf("%-16s ", p->d_name);
		if((i+1) % 5==0)
			printf("\n");
		i++;
	}
	printf("\n");
	closedir(dp);
	
	return 0;
	
}

/*
./a.out -a 로 실행시키면 숨김파일을 포함해서 모든 파일을 출력함.
*/
