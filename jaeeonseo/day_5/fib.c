#include <stdio.h>

int fib(int num)
{
	int first = 1;
	int second = 1;
	int tmp = 0;

	if(num == 1 || num == 2)
		return 1;
	
	while(num-- > 2)
	{

		tmp = first + second;
		first = second;
		second = tmp;
	}

	return tmp;
}

int main(void)
{
	int result;
	int nDigit;

	printf("계산할 피보나치 항 수를 입력하시오:\n");
	scanf("%d", &nDigit);	

	result = fib(nDigit);

	printf("fib(%d) = %d\n", nDigit ,  result);

	return 0;
}
