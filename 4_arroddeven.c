#include<stdio.h>

int main(void)
{
	int arr[] = {3, 77, 10, 7, 4, 9, 1, 8, 21, 33};
	int i,odd = 0, even = 0;
	for(i=0; i<10; i++)
	{
		if(arr[i]%2 == 0)
		{
			even+=arr[i];
		}
		else
		{
			odd+=arr[i];
		}
	}
	printf("홀수합 = %d\n",odd);
	printf("짝수합 = %d\n",even);
	return 0;
}
