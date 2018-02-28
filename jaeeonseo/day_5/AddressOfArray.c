#include <stdio.h>

int main(void)
{
	int arr[4] = {10, 20, 30, 40};
	int i;

	printf("address = %p\n", arr);

	for(i=0; i <4; i++)
	{
		printf("address = %p, arr[%d] = %d\n", &arr[i], i, arr[i]);
	}

	return 0;
}
