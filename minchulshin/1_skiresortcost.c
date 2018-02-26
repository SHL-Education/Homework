#include <stdio.h>

#define cost 37500
int main(void)
{	
	int daycount,totalcost;
	printf("임베디드 스키장에 오신것을 환영합니다!!\n");
	printf("3일 이상 이용시 이용금액의 20%할인해드립니다~\n");
	printf("이용하실 날짜를 입력해주십시오. ==> ");
	scanf("%d",&daycount);

	totalcost=partdiscount(daycount);
	printf("총 금액은 %d원 입니다.",totalcost);
	return 0;

}

int partdiscount(int daycount)
{	
	int res;
	if(daycount >=3)
	{
		res=(cost-(cost/100*20))*daycount;	
	}
	else
	{
		res=cost*daycount;
	}
}
