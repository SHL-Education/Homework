#include <stdio.h>

int main(void)
{
	int nDay;
	int nMoney;
	
	do
	{
	

		printf("몇 일 동안 장비를 대여할 예정이신가요?");
		scanf("%d", &nDay);

		if(nDay > 2)
		{
			nMoney = 37500*nDay*0.8;
		}
		else
		{
			nMoney = 37500*nDay;	
		}


		printf("대여금액: %d\n", nMoney);
	


	}while(1);

	return 0;

}
