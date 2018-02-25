#include <stdio.h>
int main(void)
{	
	int sum = sumofremainder();
	printf("1 ~ 1000 사이에 4나 6으로 나눠도 나머지가 1인 수의 합은? %d",sum);
	return 0;
}
int sumofremainder(void)
{	
	int sum = 0,i;
	for(i = 1; i <= 1000; i++)
	{
		if(i % 4 == 1 && i % 6 == 1)
		{
			sum+=i;
		}
	}
	return sum;
}
