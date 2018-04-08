#include <stdio.h>
int mult_even_odd_sum(int *arr, int size)
{
	int i, esum = 0, osum = 0;
	for(i = 0; i < size; i++)
	{
		if(i % 2)
		{
			osum += arr[i];
		}
		else
		{
			esum += arr[i];
		}	
	}
	return osum * esum;
}
int main(void)
{
	int arr[12] = {3, 77, 10, 7, 4, 9, 1, 8, 21, 33};
	int size = sizeof(arr) / sizeof(int) - 1;
	int res;
	res = mult_even_odd_sum(arr, size);
	printf("res = %d\n", res);
	return 0;
}
