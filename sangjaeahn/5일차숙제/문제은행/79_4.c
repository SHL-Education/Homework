#include <stdio.h>

#define index 10

int sum_even(int *array);
int sum_odd(int *array);

int main(void)
{
	int array[index] = {3,77,10,7,4,9,1,8,21,33};
	int mult_sum;
	
	mult_sum = sum_even(array)*sum_odd(array);
	
	printf("%d\n",mult_sum);
	

	return 0;
}

int sum_even(int *array)
{
	int i,sum=0;
	
	for(i=0;i<index;i+=2)
	{
		sum += array[i];
	}

	return sum;
}

int sum_odd(int *array)
{
	int i,sum=0;
	
	for(i=1;i<index;i+=2)
	{
		sum += array[i];
	}
	
	return sum;
}
