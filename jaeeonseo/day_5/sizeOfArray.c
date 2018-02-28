#include <stdio.h>

int main(void)
{
	int arr[3][4];

	printf("arr size = %lu\n", sizeof(arr));
	printf("arr[0] size = %lu\n", sizeof(arr[0]));
	printf("arr[1] size = %lu\n", sizeof(arr[1]));
	printf("arr[2] size = %lu\n", sizeof(arr[2]));
	

	return 0;
}
