#include <stdio.h>

void start_game(int *num)
{
	printf("게임을 몇 명이서 즐기는가 ?");
	scanf("%d", num);
	printf("몇명이 걸리게 만들것인가 ?");
	scanf("%d", check_cnt);
}

void setting_game(int num, int ccnt, int **mem, int **cnum)
{
	*mem = (int *)malloc(num);
	*cnum = (int *)malloc(ccnt);
}

void set_lose_num(int *cn, int num, int ccnt)
{
	int i;

	for(i = 0; i < ccnt; i++)
		cn[i] = rand() % num + 1;
}

int main(void)
{
	int num = 0, check_cnt;
	int *mem = NULL;
	int *check_num = NULL;

	start_game(&num, &check_cnt);
	setting_game(num, check_cnt, &mem, &check_num);

	set_lose_num(check_num, num, check_cnt);
	play_game(mem, check_num);

	return 0;
}
