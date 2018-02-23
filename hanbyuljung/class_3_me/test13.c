#include<stdio.h>

int main(void)
{

	int num;
	
	printf("정수를 입력하시오:");
	scanf("%d",&num);
	

	if(num%2)
		printf("입력된 수는 홀수 \n");
	else
		printf("입력된 수는 짝수 \n");

	return 0;

}
