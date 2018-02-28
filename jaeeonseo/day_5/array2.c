#include <stdio.h>

int main(void)
{
	int i;
	int num1_arr[] = {1, 2, 3, 4, 5};
	int num2_arr[3] = {1, 2, 3};

	int len1 = sizeof(num1_arr)/sizeof(int);
	int len2 = sizeof(num2_arr)/sizeof(int);

	printf("num1_arr length = %d\n", len1);
	printf("num2_arr length = %d\n", len2);

	for(i = 0; i < len1; i++)
	{
		printf("num1_arr[%d] = %d\n", i, num1_arr[i]);
	}

	for(i=0; i < len2; i++)
	{
		printf("num2_arr[%d] = %d\n", i, num2_arr[i]);
	}

	return 0;
}
