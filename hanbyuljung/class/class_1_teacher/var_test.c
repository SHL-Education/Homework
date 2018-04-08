#include <stdio.h>

int main(void)
{
	/* Data Type
	int, short, char, float, double, long double */

	int num1 = 3;
	int num2 = 7;
	float num3 = 7.7;
	double num4 = 3.3;

	int res1;
	double res2;

	printf("num1 = %d, num2 = %d, num3 = %f, num4 = %lf\n",
			num1, num2, num3, num4);

	res1 = num1 * num3;	// multiply
	res2 = num1 * num2;

	printf("res1 = %d, res2 = %lf\n", res1, res2);

	return 0;
}
