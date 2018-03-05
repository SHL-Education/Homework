#include <stdio.h>

float *pof2(int n1, double d1)
{

	return n1*d1;
}

int *pof1(float *subpof1(int , double))
{
	float res;
	
	res = subpof1(10, 2.4);

	printf("res = %d\n", res);

	return res;
}



//int *pof_test_main()(int, int) int (*p)() float (*p)(int, double)
//int *pof_test_main(int (*p)(float (*p)(int, double))) 
int *pof_test_main(int (*p)(float (*p)(int, double)(int))(int n1, int n2))
{
	int temp;
	
	temp = n1 + n2;

	return temp;


}


int main(void)
{

	int nRes;

	nRes = pof_test_maini(pof1(1, 1.5))(10, 11);

	return 0;


}
