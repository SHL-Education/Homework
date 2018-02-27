#include <stdio.h>

void print_seven_series(int num)
{
	int i;

	for(i=0;i<num;i++)
	{
		if(i < num - 1)
		{
			printf("%d\t", (i + 1) * 7);
		}
		else
		{
			printf("%d\n", (i + 1) * 7);
		}
	}
}

int main(void)
{
	print_seven_series(7);
	return 0;
}
