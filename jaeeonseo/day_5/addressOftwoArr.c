#include <stdio.h>

int main(void)
{
	int arr[3][4];

	printf("arr address = %p\n", arr);
	printf("arr[0] address = %p\n", arr[0]);
	printf("arr[1] address = %p\n", arr[1]);
	printf("arr[2] address = %p\n", arr[2]);

	return 0;
}
