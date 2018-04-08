#include<stdio.h>

int main(void)
{

	int num1 = 10;
	printf("result = %d\n", num1++);
	printf("result = %d\n", num1);
	
	num1 = 10;
	printf("result = %d\n", ++num1);
	printf("result = %d\n", num1);
	return 0;

}
