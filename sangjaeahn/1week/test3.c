#include <stdio.h>

int multiple3(int start, int end)
{
	int i = start, sum = 0;
	
	while(i <= end)
	{
		if(i % 3 == 0)
		{
			sum += i;
		}
		i++;
	}
	
	return sum;
}

int main(void)
{
	printf("1부터 1000사이에 3의 배수의 합은 %d 입니다.",multiple3(1,1000));
	
	return 0;
}
