#include <stdio.h>

int main(void)
{
	int num1 = 3, num2 = 7;
	int *temp = NULL;
	int *num1_p = &num1;
	int *num2_p = &num2;
	int **num_p_p = &num1_p;

	printf("*num1_p = %d\n", *num1_p);
	printf("*num2_p = %d\n", *num2_p);

	temp = *num_p_p;
	*num_p_p = num2_p;
	num2_p = temp;

	printf("num1_p = %d\n", *num1_p);
	printf("num2_p = %d\n", *num2_p);

	return 0;
}
