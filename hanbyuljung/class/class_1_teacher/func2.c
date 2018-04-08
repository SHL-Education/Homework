#include <stdio.h>

// input = 3, 6, output = 21.3
float myfunc(int num1, int num2)
{
	return num1 * num2 + 3.3;
}

int main(void)
{
	int num1 = 3, num2 = 6;
       	float res;

	res = myfunc(num1, num2);
	printf("res = %f\n", res);

	printf("this = %f\n", myfunc(num1, num2));

	return 0;
}
