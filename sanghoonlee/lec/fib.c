#include <stdio.h>

int fib(int num)
{
	if(num == 1 || num == 2)
		return 1;
	else
		return fib(num - 1) + fib(num - 2);
}

int main(void)
{
	int res, fin;
	printf("fibonacci series num: ");
	scanf("%d", &fin);
	res = fib(fin);
	printf("fib = %d\n", res);
	return 0;
}
