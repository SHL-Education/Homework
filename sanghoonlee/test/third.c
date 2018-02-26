#include <stdio.h>
// first = start, second = end
void print_even(int start, int end)
{
	int i = start;
	while(i <= end)
	{
		if(!(i % 2))
		{
			printf("even = %d\n", i);
		}
		i++;
	}
}
int main(void)
{
	print_even(1, 100);
	return 0;
}
