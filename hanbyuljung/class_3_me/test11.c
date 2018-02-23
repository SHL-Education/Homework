#include<stdio.h>
int main(void)
{

	int num1, num2;
	double real1, real2;

	printf("2개의 정수를 입력하세요:");
	scanf("%d%d", &num1, &num2);
	printf("입력된 정수: %d, %d\n", num1, num2);

	printf("2개의 실수를 입력하세요");
	scanf("%lf %lf", &real1,&real2);
	printf("입력된 실수: %.2lf, %.2lf\n", real1, real2);
	return 0;

}
