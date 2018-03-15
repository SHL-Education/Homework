#include<stdio.h>


int func(int num)
{

	return num+3;
}

int main(void)
{

	int res, num;
	
	res = func(3);

	printf("res is %d\n",res);

	return 0;
}
