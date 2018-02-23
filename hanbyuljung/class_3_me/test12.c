#include<stdio.h>

int main(void)
{

	int num;
	printf("정수를 입력하세요:");
	scanf("%d", &num);

	if(num<0)
	{
		printf("입력된 수는 0 미만\n");
	}

	if(num>=0)
	{
		printf("입력된 수는 0 이상\n");
	}
	return 0;


}
