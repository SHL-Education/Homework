#include <stdio.h>

int main(void)
{
	int i, j, k;

	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			for(k = 0; k < 5; k++)
			{
				if((i == 2) && (j == 2) && (k == 2))
				{
					printf("Error!!!\n");
					goto err_handler;
				}
				else
				{
					printf("Data\n");
				}
			}
		}
	}
	return 0;

err_handler:
	printf("Goto Zzang!\n");

	return -1;
}



