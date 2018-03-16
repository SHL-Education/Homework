#include <stdio.h>
#include <math.h>

int main(void)
{
	int x1=3,y1=6;
	int x2=4,y2=4;
	double a = sqrt(45);
	double b = sqrt(32);
	
	double sin_a = y1/a;
	double sin_b = y2/b;
	double cos_a = x1/a;
	double cos_b = x2/b;
	double sin = sin_a*cos_b - cos_a*sin_b;
	double area = a*b*sin*1/2;
	
	printf("넓이 : %lf\n", area);
	

	return 0;
}
