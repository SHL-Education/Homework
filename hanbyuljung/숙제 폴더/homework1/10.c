#include <stdio.h>

void print_rom(void)
{
	int i = 2, j = 1;

	while(i < 10)
	{
		while(j < 10)
		{
			printf("%d x %d = %d\n", i, j, i * j);
			j++;
		}
		j = 1;
		i++;
	}
}

int main(void)
{
	print_rom();
	return 0;
}


