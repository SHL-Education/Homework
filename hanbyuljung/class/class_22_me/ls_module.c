#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

void recursive_dir(char *dname);

int main(int argc, char *argv[])
{
	recursive_dir(".");
	return 0;
}

void recursive_dir(char *dname)
{
	struct dirent *p;
	struct stat buf;
	DIR *dp;
	chdir(dname);
	dp = opendir(".");
	printf("\t%s:\n",dname);
	while(p = readdir(dp))
		printf("%s\n",p->d_name);
	rewinddir(dp); // 되감기 한다. 포인터의 위치를 맨앞으로 가져다 준다.
	while(p = readdir(dp))
	{
		stat(p->d_name, &buf);
		if(S_ISDIR(buf.st_mode))
			if(strcmp(p->d_name,".") && strcmp(p->d_name,".."))
			// 0일때 돌아가는거니 둘다 아닐 때만 리컬시브로 어가란 뜻이다.
				recursive_dir(p->d_name);
	}
	// 만약에 chdir 하기전에 마지막이.이면 상위로 가면 안되니까 if로 .이 아닐때만.
	// <시험 문제> 상위돌다가 바꿔야하는 프로그램.
	chdir("..");
	closedir(dp);
}

