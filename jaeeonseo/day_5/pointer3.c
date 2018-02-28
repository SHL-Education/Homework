#include <stdio.h>

int main(void)
{
	int num = 3;

	*(&num) += 30;

	printf("num = %d\n", num);
	
	return 0;
}
