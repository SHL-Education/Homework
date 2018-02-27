#include <stdio.h>

int main(void)
{
	int arr[4][4];
	int i, j;

	for(i=0; i < 4; i++)
	{
		for(j=0; j < 4; j++)
		{
			if(i == j)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}


	for(i=0; i < 4; i++)
	{
		for(j=0; j < 4; j++)
		{
			printf("%d", arr[i][j]);
		}

		printf("\n");
	}

	return 0;

}
