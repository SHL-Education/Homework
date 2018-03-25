#include <stdio.h>

void make_fib(int *p, int last)
{
	int i = 2;

	for(; i < last; i++)
		p[i] = p[i - 2] + p[i - 1];	// 피보나치 수열의 방정식
}

int get_even_odd_diff(int *p)
{
	int i, even = 0, odd = 0;

	for(i = 0; i < 27; i++)		// 배열의 모든 원소를 체크함.
	{
		if(p[i] % 2)
			odd += p[i];	// 배열의 원소 중에 홀수의 합을 구함.
		else
			even += p[i];	// 배열의 원소 중에 짝수의 합을 구함.
	}

	return odd - even;
}

int main(void)
{
	int res;
	int fib_arr[27] = {1, 1};
	make_fib(fib_arr, 27);	// 피보나치 수열을 배열을 통해 만듬.
	res = get_even_odd_diff(fib_arr);	// 피보나치 배열의 "홀수 원소의 합 - 짝수 원소의 합"을 출력함.
	printf("res = %d\n", res);

	return 0;
}

/*
피보나치 수열을 배열을 통해 구현하고, 그 중에서 홀수의 합과 짝수의 합의 차를 출력함.
*/
