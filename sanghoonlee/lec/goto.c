#include <stdio.h>

int main(void)
{
	int i, j, k, flag = 0;

	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			for(k = 0; k < 5; k++)
			{
				if((i == 2) && (j == 2) && (k == 2))
				{
					printf("Error!!!\n");
					flag = 1;
				}
				else
				{
					printf("Data\n");
				}

				if(flag)
				{
					break;
				}
			}

			if(flag)
			{
				break;
			}
		}

		if(flag)
		{
			break;
		}
	}
	
	return 0;
}
