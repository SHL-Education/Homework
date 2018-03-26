#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void set_rand_mem(int *mem)	// 배열에 1~4096 숫자를 setting함.
{
	int i;

	for(i = 0; i < 100; i++)
		mem[i] = rand() % 4096 + 1;
}

void print_mem(int *mem)	// 배열의 모든 원소를 출력
{
	int i;

	for(i = 0; i < 100; i++)
		printf("mem[%d] = %d\n", i, mem[i]);
}

void check_waste_mem(int *mem, int *waste)	// mem배열의 각 원소에서 4096에 대해 낭비되는 만큼의 수를 waste 배열에 setting함.
{
	int i;

	for(i = 0; i < 100; i++)
		waste[i] = 4096 - mem[i];
}

int sum_waste(int *waste)	// waste배열의 모든 원소의 합을 구함.
{
	int i, tot = 0;

	for(i = 0; i < 100; i++)
		tot += waste[i];

	return tot;
}

int main(void)
{
	int dissipation;
	int mem[100] = {0};
	int waste_mem[100] = {0};

	srand(time(NULL));
	set_rand_mem(mem);

	print_mem(mem);

	check_waste_mem(mem, waste_mem);

	print_mem(waste_mem);

	dissipation = sum_waste(waste_mem);
	printf("dissipation = %d\n", dissipation);

	return 0;
}

/*
1~4096의 수를 배열에 셋팅하고, 4096에 대해 낭비되는 수를 배열에 셋팅해서 모든 원소를 더한다.
*/
