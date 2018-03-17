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
		emp[i].money = rand() % 30 + 1;
}

float get_mean(sal * emp)
{
	int i, sum = 0;

	for(i = 0; i < 7; i++)
		sum += emp[i].money;

	return sum / 7.0;
}

void get_more(sal *emp, int *idx, float mean)
{
	int i, k = 0;

	for(i = 0; i < 7; i++)
		if(emp[i].money > mean)
			idx[k++] = i;
}

void print_name(sal *emp, int *idx)
{
	int i;

	for(i = 0; idx[i] != -1; i++)
		printf("name = %s\n", emp[idx[i]].name);
}

int main(void)
{
	float mean;

	int idx[7] = {-1, -1, -1, -1, -1, -1, -1};
	sal emp[7] = {{"Chul Su", }, {"Myung jin", }, {"Mu Sung", }, {"Kyung Feel", },
				{"Jin Tae", }, {"Young Su", }, {"Kyu Chul", }};

	srand(time(NULL));

	set_rand_pay(emp);
	mean = get_mean(emp);
	get_more(emp, idx, mean);
	print_name(emp, idx);

	return 0;
}
