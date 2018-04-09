#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

typedef struct
{
	char fname[20];
	int fsize;
}F_info;

int file_size(int fd)
{
	int fsize, old;
	old = lseek(fd,0,SEEK_CUR);
	fsize = lseek(fd, 0, SEEK_END);
	// pos가 위에서 한번 계산하면서 위치가 뒤로 set이 되기에 old로 다시 set해준다.
	lseek(fd, old, SEEK_SET);
	return fsize;
}

int main(int argc, char *argv[])
{
	int src, dst, ret;
	char buf[1024];
	F_info info;
	int i;

	// -1 은 배열 선언시에 들어오는 갯수와 처음 저장되는 갯수는 -1이기 때문에.
	// dst 는 마지막 녀석이 저장이 된다. 압축 위치가 된다.
	dst = open(argv[argc -1], O_WRONLY | O_CREAT |O_TRUNC, 0644);
	// ./a.out a.txt b.txt c.txt res.tar 이라고 할때 , a.txt, b.txt, c.txt만 보려고.-2임
	for(i=0; i<argc-2;i++)
	{
		//+1은 실행 파일을 제외하고 시작하기 위해서
		src = open(argv[i+1], O_RDONLY);
		// 파일의 이름을 info.fname에 복사한다.
		strcpy(info.fname, argv[i + 1]);
		info.fsize = file_size(src);
		write(dst, &info, sizeof(info));
		while(ret = read(src, buf, sizeof(buf)))
			write(dst, buf, ret);
		close(src);
	}
	close(dst);
	return 0;
}
