#include <stdio.h>

int sum(int s, int e, int t1, int t2)
{
	int i, sum = 0;

	for(i = s; i <= e; i++)
		if(((i % 4) == 1) || ((i % 6) == 1))
			sum += i;

	return sum;
}

int main(void)
{
	printf("sum of 3 series = %d\n", sum(1, 1000, 4, 6));
	return 0;
}
