#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

int daemon_init(void)
{
	int i;
	if(fork() > 0)
		// 부모를 죽임
		exit(0);
	// 인간에서 악마로 됨. damon 이 된다.
	setsid();
	// root라는 디렉토리로 감.
	chdir("/");
	// root 의 권한을 다 주겠다. chmod 0777
	umask(0);
	// 기본적으로 리눅스에서 64개의 기본 입력, 출력, 에러.... 해서 64개를 켜줌. 그걸 다 꺼줌.
	for(i = 0; i<64;i++)
		close(i);
	// 자식이 죽어도 무시해라.
	signal(SIGCHLD, SIG_IGN);
	return 0;
}

int main(void)
{
	// 게임 서버, 포털 , 
	daemon_init();
	for(;;)
		;
	return 0;
}
