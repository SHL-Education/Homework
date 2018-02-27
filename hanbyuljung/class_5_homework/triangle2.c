#include<stdio.h>
#include<math.h>

int angle(int a, int b)
{
	if(b<90 && b>0)
		return;
	else if(b == 90)
		return a*b/2;
	else if(b>90 && b<180)
		return ;
	else 
		return 0;
}


int main(void)
{
	int a, b,c;	

	printf("삼각형의 밑 변을 입력하시오.\n");
	scanf("%d",&a);

	printf("삼각형의 밑 변과 이루는 다른변이 이루는 각도는?\n");
	scanf("%d",&b);


	printf("삼각형의 넓이 = %d\n",angle);
	return 0;
}
