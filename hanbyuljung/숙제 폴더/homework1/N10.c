#include <stdio.h>

void print_rom(void)
{
	int i = 2;
	int j = 1;

	for(i=2;i < 10;i++)
	{
		for(j=1; j<10 ;j++)
		{
			printf("%d x %d = %d\n", i, j, i * j);
		
		}
		j = 1;
		
	}
}

int main(void)
{
	print_rom();
	return 0;
}


