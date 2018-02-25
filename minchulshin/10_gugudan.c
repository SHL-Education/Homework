#include<stdio.h>
void gugudan(void);
int main(void)
{
	char yn = 0;
	printf("구구단 출력은 y, 종료는 n을 입력해주십시오. -->");
	scanf("%c",&yn);
	if(yn == 'y')
	{	
		printf("구구단 출력결과 -->\n");
		gugudan();
	}
	else if(yn == 'n')
	{
		printf("다음에 또 찾아주십시오");
	}
	else
	{
		printf("잘못 입력하셨습니다.프로그램을 종료합니다.");
	}
	return 0;
}
void gugudan(void)
{
	for(int i = 1; i <= 9; i++)
	{
		printf("--%d단\n",i);
		for(int j = 1; j <= 9; j++)
		{
			printf(" %d * %d = %d \n",i,j,i*j);
		}
	}	
}
