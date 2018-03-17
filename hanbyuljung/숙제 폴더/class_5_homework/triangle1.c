#include<stdio.h>

int main(void)
{
	int a, b;	

	printf("삼각형의 밑 변을 입력하시오.\n");
	scanf("%d",&a);

	printf("삼각형의 높이를 입력하시오.\n");
	scanf("%d",&b);

	printf("삼각형의 넓이 = %d\n",a*b/2);
	return 0;
}
