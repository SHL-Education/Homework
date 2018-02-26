#include <stdio.h>

int main(void)
{
	int nMultipleNum;
	int i;	

	printf("출력을 원하는 구구단 수를 입력하시오:");
	scanf("%d", &nMultipleNum);

	for(i=1; i < 10; i++)
	{
		printf("%d*%d=%d\n",nMultipleNum, i, nMultipleNum*i);
	}

	return 0;
}

