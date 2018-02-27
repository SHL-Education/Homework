#include <stdio.h>

void print_rom(void)
{
	int i = 2, j = 1;

	for(i=2;i<10;i++)
	{
		for(j=1;j<10;j++)
		{
			printf("%d x %d\n", i,j,i*j);
		}
		j=1;
		printf("\n");
	}
/*
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
*/
}

int main(void)
{
	print_rom();
	return 0;
}


