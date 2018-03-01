#include <stdio.h>

void compute_int_bit(char *val, int size)
{
	int i, j;
	unsigned char comp = 0;

	printf("val = ");

	for(i = size - 1; i >= 0; i--)
	{
		comp = 128;
		for(j = 1; j <= 8; j++)
		{
			if(i == size - 1 && j == 1)
			{
				printf("%d ", val[i] & comp ? 1 : 0);
			}
			else
			{
				printf("%d", val[i] & comp ? 1 : 0);
			}
			comp >>= 1;
		}
		printf(" ");
	}
}

int main(void)
{
	int size = sizeof(int);
	int val = 2004016;

	compute_int_bit((char *)&val, size);

	return 0;
}
