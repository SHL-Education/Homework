#include <stdio.h>

int main(void)
{
	int i;
	int num1_arr[7] = {1, 2, 3};

	for(i=0; i < 7; i++)
	{
		printf("num1_arr[%d] = %d\n", i, num1_arr[i]);
	}

	return 0;
}
