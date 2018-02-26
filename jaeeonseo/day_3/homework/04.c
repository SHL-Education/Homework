#include <stdio.h>

int main(void)
{
	int i;
	int nSum;

	for(i=1; i < 1001; i++)
	{
		if((i%4 == 1)&&(i%6 == 1))
		{
			nSum += i;
		}
	}

	printf("1에서 1000사이 4또는6으로 나눠도 나머지가 1인 수의 합:%d\n", nSum);
}	
