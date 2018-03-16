#include <stdio.h>
#include <math.h>

int** func(int arr[2][3])
{
	int i;
	
	for(i=0;i<3;i++)
	{
		arr[1][i] = pow(arr[1][i],2);
	}
	
	return arr;
}

void sappy(int arr[2][3], int **func(int arr[2][3]))
{	
	int i,j;
	
	int **arr1 = func(arr);

	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	int arr[2][3] = {{2,4,6},{2,4,6}};
	
	sappy(arr,func);
	return 0;	
}
