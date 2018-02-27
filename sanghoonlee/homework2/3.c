#include <stdio.h>

int sum(int s, int e, int t)
{
	int i, sum = 0;

	for(i = s; i <= e; i++)
		if(!(i % 3))
			sum += i;

	return sum;
}

int main(void)
{
	printf("sum of 3 series = %d\n", sum(1, 1000, 3));
	return 0;
}
