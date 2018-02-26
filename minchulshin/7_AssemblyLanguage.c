#include <stdio.h>
int mult2(int num)
{
	return num*2;
}
int main(void)
{
	int i, sum = 0, result;
	for(i = 0; i < 5; i++)
	{
		sum+=i;
	}
	result = mult2(sum);
	return 0;
}
