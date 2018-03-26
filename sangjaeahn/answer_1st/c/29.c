#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct salary
{
	char name[11];
	int money;
} sal;

void set_rand_pay(sal *emp)
{
	int i;

	for(i = 0; i < 7; i++)
		emp[i].money = rand() % 30 + 1;	// 모든 사람들의 money를 1~30의 숫자 중에서 랜덤으로 셋팅함.
}

float get_mean(sal * emp)
{
	int i, sum = 0;

	for(i = 0; i < 7; i++)
		sum += emp[i].money;

	return sum / 7.0;	// 모든 사람들의 money의 평균을 반환함.
}

void get_more(sal *emp, int *idx, float mean)
{
	int i, k = 0;

	for(i = 0; i < 7; i++)
		if(emp[i].money > mean)
			idx[k++] = i;	// 평균보다 money가 많은 사람의 인덱스를 저장함.
}

void print_name(sal *emp, int *idx)
{
	int i;

	for(i = 0; idx[i] != -1; i++)	// -1이 될때까지(평균보다 적은 money를 갖는사람이 나올때까지) 반복해서 출력
		printf("name = %s\n", emp[idx[i]].name);
}

int main(void)
{
	float mean;

	int idx[7] = {-1, -1, -1, -1, -1, -1, -1};
	sal emp[7] = {{"Chul Su", }, {"Myung jin", }, {"Mu Sung", }, {"Kyung Feel", },
				{"Jin Tae", }, {"Young Su", }, {"Kyu Chul", }};

	srand(time(NULL));

	set_rand_pay(emp);	// 모든 사람의 money 를 초기화함.
	mean = get_mean(emp);	// 모든사람의 money의 평균값을 구함.
	get_more(emp, idx, mean);	// 평균보다 많은 money를 갖는 사람을 찾음.
	print_name(emp, idx);	// 평균보다 많은 moeny를 갖는 사람의 이름 을 모두 출력함.

	return 0;
}
