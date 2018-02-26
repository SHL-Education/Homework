#include<stdio.h>
int main(void)
{	
	int sum = multipleofthree();
	printf("1 ~ 1000 사이에 3의 배수의 합은? %d",sum);
	return 0;
}
int multipleofthree(void)
{	
	int sum = 0,i;
	
	for(i = 1; i <=1000; i++)
	{
		if(i % 3 == 0)
		{
			sum+=i;
		}
	}
	return sum;
}
