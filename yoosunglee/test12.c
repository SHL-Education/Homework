#include<stdio.h>

int fib(int num)
{
	if(num == 1 || num == 2)
		return 1;
	else
		return fib(num-1) + fib(num-2);

}


int main(void)
{

	int res , final_val;

	printf("피보나치 수열의 항의 개수를 입력하시오 : ");
	scanf("%d",&final_val);
	res = fib(final_val);
	printf("%d번째 항의 수는 %d\n",final_val ,res);

	return 0;
}
