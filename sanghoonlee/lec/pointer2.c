#include <stdio.h>

void add_arr(int *arr)
{
	int i;
	for(i = 0; i < 3; i++)
	{
		arr[i] += 7;
	}
}
void print_arr(int *arr)
{
	int i;
	for(i = 0; i < 3; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}
int main(void)
{
	int i;
	int arr[3] = {1, 2, 3};
	add_arr(arr);
	print_arr(arr);

	printf("real\n");

	for(i = 0; i < 3; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	return 0;
}



