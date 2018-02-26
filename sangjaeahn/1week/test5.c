#include <stdio.h>

int lastvalue(int n);

int main(void)
{
	int n = 35;

	printf("마지막 항의 값은 %d 입니다.\n", lastvalue(n));
	return 0;
}

int lastvalue(int n)
{
	return 7*n;
}
