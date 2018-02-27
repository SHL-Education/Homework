#include<stdio.h>
int main(void)
{
	int arr1[] = {3, 77, 10, 7, 4, 9, 1, 8, 21, 33};
	int temp[10] = {0,0,0,0,0,0,0,0,0,0} ;
	int i,j;
	for(i = 0; i < 10; i++)
	{
		printf("arr[%d] = %d\n",i,arr1[i]);
	}
	for(i = 0, j = 9; i < 10, j = 0; i ++, j--)
	{
		temp[i]+=arr1[j];
	}
	for(i = 0; i < 10; i++)
	{
		printf("arr[%d] = %d\n",i,temp[i]);
	}
	return 0;
}
