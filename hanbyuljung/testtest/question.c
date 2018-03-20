#include<stdio.h>

int main(void)
{
	int a;
	printf("값을 입력하시오:");
	scanf("%d",&a);
	printf("%d\n", a&(-4095));

	return 0;
}
