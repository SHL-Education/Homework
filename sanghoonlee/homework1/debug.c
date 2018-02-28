#include <stdio.h>

int main(void)
{
	int number = 1;

	while(1)
	{
		printf("number = %d\n", number);
		number += number;

		if(number == 100)
			break;
	}
}
