#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void set_rand_mem(int *mem)
{
	int i;

	for(i = 0; i < 100; i++)
		mem[i] = rand() % 4096 + 1;	// 1~4096 의 숫자를 mem배열에 셋팅함.
}

void print_mem(int *mem)
{
	int i;

	for(i = 0; i < 100; i++)
		printf("mem[%d] = %d\n", i, mem[i]); //mem 배열의 모든 원소를 출력함.
}

int main(void)
{
	int mem[100] = {0};

	srand(time(NULL));
	set_rand_mem(mem);	// mem 배열 셋팅

	print_mem(mem);		// mem 배열 출력

	return 0;
}

/*
1~4096의 숫자를 100개 셋팅하고 출력함.
*/
