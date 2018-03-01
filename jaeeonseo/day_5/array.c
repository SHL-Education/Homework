#include <stdio.h>

int main(void)
{
	int i;
	int num[7];

	for(i =0; i < 7; i++)
	{
		num[i] = i+1;
		printf("num[%d] = %d\n", i, num[i]);
	}

	return 0;
}
