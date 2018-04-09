#include<stdio.h>
int main(void)
{

	int num1;
	float num2;
	printf("정수를 입력하세요: ");
	scanf("%d", &num1);
	
	printf("정수를 입력하세요: ");
	scanf("%f", &num2);
	printf("입력된 2개의 data:%d, %.2f\n", num1,num2);
	return 0;

}
