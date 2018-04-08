#include <stdio.h>

int test(int num1, int num2, int num3, int num4, int num5)
{
	return num1 + num2 + num3 + num4 + num5;
}

int main(void)
{
	int num1 = 2, num2 = 4, num3 = 6, num4 = 8, num5 = 10, res;

	res = test(num1, num2, num3, num4, num5);
	printf("res = %d\n", res);

	return 0;
}
