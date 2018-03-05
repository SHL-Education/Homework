#include <stdio.h>

int main(void)
{
	int arr[3] = {1, 2, 3};
	int *p = arr;
	int i;

	for(i = 0; i < 3; i++)
		printf("p[%d] = %d\n", i, p[i]);

	return 0;
}
