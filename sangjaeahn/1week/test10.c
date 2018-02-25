#include <stdio.h>

int main(void)
{
	int i,n;

	for(i=1;i<=9;i++)
	{
		for(n=1;n<=10;n++)
		{
			printf("%d * %d = %d\n", i,n,i*n);
		}

		printf("\n");
	}

	return 0;
}
