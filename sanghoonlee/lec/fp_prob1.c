#include <stdio.h>

float pof_test1(int n1, int n2)
{
	return (n1 + n2) * 0.23573;
}

int pof_test2(float n1, double n2, int n3)
{
	return (n1 + n2 + n3) / 3.0;
}

// int (*)(float, double, int) pof_test_main(float (*)(int, int))// int (* pof_test_main(float (*)(int, int)))(float, double, int)
int (* pof_test_main(float (*p)(int, int)))(float, double, int)
{
	float res;
	res = p(4, 3);
	printf("internal ptm res = %f\n", res);
	return pof_test2;
}

int main(void)
{
	int res;
	res = pof_test_main(pof_test1)(3.7, 2.4, 7);
	printf("pof_test_main res = %d\n", res);
	return 0;
}





