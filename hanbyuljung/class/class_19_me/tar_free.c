#include<fcntl.h>
#include<unistd.h>

typedef struct
{
	char fname[20];
	int fsize;
}F_info;

#define min(x,y)	(((x) <(y)) ?(x) :(y))


int main(int argc, char *argv[])
{
	int src,dst, len,ret;
	F_info info;
	char buf[1024];

	// argv[1]는./a.out xxxx.tar 을 풀때 xxx.tar을 압축 해제 하겠다하여 파일을 여는것.
	src = open(argv[1], O_RDONLY);
	// 압축 해제 할 파일을 읽는 다는 소리이다.
	// 우리가 해제할 압축 파일에 3개가 있기 때문에 3번 돌 것이란 소리이다.
	while(read(src, &info, sizeof(info)))
		{
			// dst (디스크립터:식별자)에 구조체가 가진 이름을 읽음 
			dst = open(info.fname, O_WRONLY | O_TRUNC |O_CREAT, 0644);
			while(info.fsize >0)
			{
				len = min(sizeof(buf),info.fsize);
				ret = read(src, buf, len);
				write(dst, buf, ret);
				info.fsize -= ret;
			}
			close(dst);
		}
	close(src);
	return 0;
}
