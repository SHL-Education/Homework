#include <stdio.h>
#include <math.h>
#define PI 3.141592

int main(void)
{
	double a, b, angle, area;
	
	printf("삼각형의 두변의 길이와 각도를 차례로 입력하시오.\n");
	scanf("%lf %lf %lf",&a,&b,&angle);	 

	area = (1/2)*a*b*sin(angle*(PI/180));	
	
	printf("삼각형 넓이는 %lf입니다. \n",area);
	return 0;
}

