#include <stdio.h>

int myfunc(int num1, int num2)
{
	return num1*num2 + 3.3;
	//return num*2;
	//return num + 3;
	//return num<<1;
}

void test(void)
{
//	printf("I can call myFunc()\n");
//	return myfunc(a, b);

}

int sumFunc(int a, int b, int c, int d, int e)
{
	
	return a+b+c+d+e;

}


int main(void)
{
	//int num1 = 3, num2 = 6;

	//res = myfunc(num1, num2);
	//printf("res=%.lf\n", test(num1, num2));

	printf("sum:%d\n",sumFunc(2, 4, 6, 8, 10));

	return 0;
}
