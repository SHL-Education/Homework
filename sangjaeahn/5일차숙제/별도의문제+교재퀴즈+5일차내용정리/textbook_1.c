#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	int i,j;
	double bankbook[7];
		
	for(i=0;i<7;i++)
	{
		j = rand() % 6;
	
		bankbook[i] = j*100;
		bankbook[i] = bankbook[i]*1.04*1.04*1.04;
	}
	
	printf("7개의 통장의 각각의 총액은 다음과 같습니다.\n");
	
	for(i=0;i<7;i++)
	{
		printf("%lf ",bankbook[i]);
	}
	
	printf("\n");
	
	return 0;
}
