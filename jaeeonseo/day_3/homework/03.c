#include <stdio.h>

int main(void)
{
	int nSum;
	int i;
	
	
	for(i=1; i <1001; i++)
	{
		if(!(i%3))
		{
			nSum += i;
		}

	}

	printf("1과 1000사이의 3의 배수의 합:%d\n", nSum);
 
 }
