#include <stdio.h>

int arith_seq(int *arr, int size)
{
	return size * ((2 * arr[0]) + (size - 1) * (arr[1] - arr[0])) / 2;
}

int for_impl(int *arr, int size)
{
	int i, sum = 0;

	for(i = 0; i < size; i++)
		sum += arr[i];

	return sum;
}

void init_arr(int *arr, int size)
{
	int i;

	for(i = 0; i < size; i++)
		arr[i] = 2 * (i + 1);
}

int main(void)
{
	int arr[11] = {0};
	int size = sizeof(arr) / sizeof(int) - 1;
	int (* func)(int *, int);

	init_arr(arr, size);

	func = arith_seq;
	printf("arith_seq = %d\n", func(arr, size));
	func = for_impl;
	printf("for_impl = %d\n", func(arr, size));

	return 0;
}
