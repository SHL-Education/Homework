#include <stdio.h>

int sum(int start, int end);

int main(void)
{
	int start = 1, end = 1000;

	printf("1~1000사이에 4나 6으로 나눠도 나머지가 1인 수의 합은 %d 입니다\n.", sum(1,1000));
	return 0;
}

int sum(int start, int end)
{
	int i = start, sum = 0;
	
	while(i<=end)
	{
		if(i%4==1 && i%6==1)
		{	
			sum += i;
		}
	
		i++;
	}

	return i;
}
