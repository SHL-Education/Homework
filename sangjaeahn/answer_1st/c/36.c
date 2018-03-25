#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int com;
int user;

void start_game(void)	// 컴퓨터의 숫자를 0~2 중에 임의로 정함.
{	
	com = rand() % 3;
}

void select_user(void)	// 유저의 숫자를 정함.
{
	printf("가위 = 0, 바위 = 1, 보 = 2, 고르시오: ");
	scanf("%d", &user);
}

void check_winner(void)
{
	if(com == user)
	{
		printf("비김\n");
		return;
	}

	switch(com)
	{
		case 0:
			if(user == 1)
			{
				printf("사용자 승리\n");
				break;
			}
			if(user == 2)
			{
				printf("사용자 패배\n");
				break;
			}
		case 1:
			if(user == 0)
			{
				printf("사용자 패배\n");
				break;
			}
			if(user == 2)
			{
				printf("사용자 승리\n");
				break;
			}
		case 2:
			if(user == 0)
			{
				printf("사용자 승리\n");
				break;
			}
			if(user == 1)
			{
				printf("사용자 패배\n");
				break;
			}	
	}
}

int main(void)
{
	srand(time(NULL));

	start_game();
	select_user();
	check_winner();

	return 0;
}

/*
컴퓨터의 숫자를 임의로 정하고, 유저의 숫자를 입력받아서 가위바위보 게임을 함.
*/
