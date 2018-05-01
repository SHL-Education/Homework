#include<stdio.h>

int my_func(int num)
{
	return num *2;
}

int main(void)
{
	int res, num= 2;
	res = my_func(num);
	printf("res = %d\n", res);
	return 0;
}



