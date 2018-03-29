#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>

void gogogo(int voidv)
{
	printf("SIGINT Accur!\n");
	exit(0);
}

int main(void)
{	// 시그널 종류 , 행동지침
	signal(SIGINT, gogogo);
	for(;;)
	{
		printf("kill Test \n");
		sleep(2);
	}

	return 0;
}

// gcc -o test test.c
// ./test & 백그라운드에서 실행한다는 뜻이다.
// 백그라운드라 터미널에서 계속 살아난다.
// & 로 실행을 하면 pid 값이 나옴.
// ctrl + c 가 안꺼지는 이유는 백그라운드로 들어가면 제어권이 사라져서 그럼.

