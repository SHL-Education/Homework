#include <stdio.h>

int sum_of_odd(int *arr)
{
	int i,sum=0;
	
	for(i=0;i<27;i++)
	{
		if(arr[i]%2)
		{
			sum += arr[i];
		}
	}
	
	return sum;
}

int sum_of_even(int *arr)
{
	int i,sum=0;
	
	for(i=0;i<27;i++)
	{
		if(!arr[i]%2)
		{
			sum += arr[i];
		}
	}

	return sum;
}

int main(void)
{
	int arr[27] = {1,1,0,};
	int i,even,odd;
	
	for(i=2;i<27;i++)
	{
		arr[i] = arr[i-1] + arr[i-2];
	}

	odd = sum_of_odd(arr);
	even = sum_of_even(arr);

	for(i=0;i<27;i++)
	{
		printf("%d ", arr[i]);
	}

	printf("홀수들의 합 - 짝수들의 합 = %d\n", odd-even);

	return 0;
}
