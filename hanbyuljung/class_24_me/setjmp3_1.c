#include<stdio.h>
#include<signal.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

void my_sig(int signo)
{
	printf("입력 시간이 늦었습니다 . 술마시세요!!!\n");
	exit(0);
}

void game(int random)
{
	char buf[1024];
	int ret;
	int i=0;	
	int setnum;
	signal(SIGALRM, my_sig);
	printf("술게임을 시작합니다\n");
	printf("내가 내는 번호를 맞춰 보세요!\n");
	while(i<5)
	{
		alarm(2);
		read(0,buf,sizeof(buf));
		setnum = atoi(buf);
		if(setnum == random){
			printf("맞추셨습니다! 술 드세요!!!\n");
			exit(0);
		}
		else if(setnum > random){
			printf("너 높다.\n");
			alarm(2);	
		}
		else if(setnum < random){
			printf("너 낮다.\n");
			alarm(2);
		}
		i++;
	}
}
int main(void)
{
	int random;

	srand(time(NULL));
	random = rand()% 26 +1;
	
//	longjmp(env, 1);
	game(random);
}
			




