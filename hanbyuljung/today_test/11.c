#include<stdio.h>

double a=4.0,b=5.0,e=1.0;
int c=2, d=1, f=0;
double res1,res2,res3;

void cal()
{
	double res;
	c++;
	d++;
	f++;

	res1 = a/(double)(c);
	res2 = b/(double)(d);
	res3 = e/(double)(f);
}

int main(void)
{

	printf("4x^2 +5x +1 정적분 구하기 ");

	cal();
	printf("4x^2 +5x +1  -->> %.2lfx^%d +%.2lfx^%d + %.2lfx^%d", res1,c,res2,d,res3,f);


	return 0;
}


