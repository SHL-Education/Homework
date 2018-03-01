#include <stdio.h>

int main(void)
{
	int arr[2][2] = {{10, 20}, {30, 40}};
	int i, j;

	for(i=0; i < 2; i++)
	{

		for(j=0; j < 2; j++)
		{

			printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
		}
	}


	return 0;

}
