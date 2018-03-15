#include<stdio.h>


int fac(int num)
{
	if(num == 0)
		return 1;
	else
		return num * fac(num-1);

}

int main(void)
{

	int res,final_val;
	printf(" 팩토리얼 항의 수를 입력 하시오 : ");
	scanf("%d",&final_val);
	res = fac(final_val);
	printf("%d항의 수는 %d\n" , final_val,res);

	return 0;
}
