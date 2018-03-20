#include<stdio.h>


int main(void)
{
	int a;
	printf("임의의 값을 입력하시오.:");
	scanf("%d", &a);
	printf("%u\n", a&-134217728);

	return 0;
}
