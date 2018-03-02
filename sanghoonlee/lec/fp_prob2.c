#include <stdio.h>

//int(*)(int, int)
int pof1(int n1, int n2)
{
	return n1 + n2;
}

//int(*)(int, int) subpof1(int)
int (* subpof1(int n))(int, int)
{
	printf("n = %d\n", n);
	return pof1;
}

//float (*)(int, double)
float pof2(int n1, double n2)
{
	return n1 * n2;
}

//int(*)(int, int) (*)(int) pof_test_main(float (*)(int, double))
//int(*)(int, int) (* pof_test_main(float (*)(int, double)))(int)

//int(*(* pof_test_main(float (*)(int, double)))(int))(int, int)
//int(*)(int, int) (* pof_test_main(float (*)(int, double)))(int)
//int(*)(int, int) (*)(int) pof_test_main(float (*)(int, double))
int(*(* pof_test_main(float (*p)(int, double)))(int))(int, int)
{
	float res;
	res = p(3, 7.7);
	printf("res = %f\n", res);
	return subpof1;
}

int main(void)
{
	int res;
	res = pof_test_main(pof2)(3)(7, 3);
	printf("res = %d\n", res);
	return 0;
}







