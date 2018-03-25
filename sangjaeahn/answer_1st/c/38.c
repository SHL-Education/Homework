#include <stdio.h>

int arith_seq(int *arr, int size)
{
	return size * ((2 * arr[0]) + (size - 1) * (arr[1] - arr[0])) / 2;
}

int for_impl(int *arr, int size)	// arr 배열의 모든 원소의 합을 구함.
{
	int i, sum = 0;

	for(i = 0; i < size; i++)
		sum += arr[i];

	return sum;
}

void init_arr(int *arr, int size)	// arr 배열에 2의 배수를 셋팅함.
{
	int i;

	for(i = 0; i < size; i++)
		arr[i] = 2 * (i + 1);
}

int main(void)
{
	int arr[11] = {0};
	int size = sizeof(arr) / sizeof(int) - 1;
	int (* func)(int *, int);	// int 포인터와 int를 인자로 하고 int를 반환하는 함수 포인터.

	init_arr(arr, size);

	func = arith_seq;
	printf("arith_seq = %d\n", func(arr, size));
	func = for_impl;
	printf("for_impl = %d\n", func(arr, size));

	return 0;
}

/*

*/
