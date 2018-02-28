#include <stdio.h>
void rev_order(int *arr1, int *arr2, int size)
{
	int i, j;
	for(i = size - 1, j = 0; i >= 0; i--, j++)
	{
		arr2[j] = arr1[i];
	}
}
void print_arr(int *arr, int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		if(i != size - 1)
			printf("%d ", arr[i]);
		else
			printf("%d\n", arr[i]);
	}
}
int main(void)
{
	int arr[12] = {3, 77, 10, 7, 4, 9, 1, 8, 21, 33};
	int reverse_order[12] = {0};
	int size = (sizeof(arr) / sizeof(int)) - 1;
	print_arr(arr, size);
	rev_order(arr, reverse_order, size);
	print_arr(reverse_order, size);
	return 0;
}
