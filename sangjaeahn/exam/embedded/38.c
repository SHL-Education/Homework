#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int sum_of_formula(int arr[])
{
	int n = sizeof(arr)/sizeof(int);
	double sum;

	sum = n*(arr[0]+arr[n-1])/2;
	return sum;
}

int sum_of_for(int arr[])
{
	int i, sum=0;
	
	for(i=0;i<18;i++)
	{
		sum += arr[i];
	}

	return sum;
}


int main(void)
{
	int arr[18] = {3,6,9,12,15,18,21,24,27,30,33,36,39,42,45,48,51,54};
	
/*
	if(sum_of_formula(arr) == sum_of_for(arr))
	{
		printf("결과가 같습니다,\n");
	}
	else
	{
		printf("결과가 다릅니다.\n");
	}
*/


	printf("%d\n", sum_of_formula(arr));
	printf("%d\n", sum_of_for(arr));


	return 0;
}
