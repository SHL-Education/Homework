#include<stdio.h>
#include<math.h>
#include<conio.h>

#define PI 3.14

double getRadian(int num)
{
	return num*(PI/180);
}


double angle(int a, int b)
{

	double num = getRadian(b);
	return a*b/2*sin(num);
}


int main(void)
{
	int a, b,c;	

	printf("삼각형의 밑 변을 입력하시오.\n");
	scanf("%d",&a);

	printf("삼각형의 밑 변과 이루는 다른변이 이루는 각도는?\n");
	scanf("%d",&b);


	printf("삼각형의 넓이 = %.3lf\n",angle(a,b));
	return 0;
}
