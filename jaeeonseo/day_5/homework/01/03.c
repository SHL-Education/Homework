#include <stdio.h>

int main(void)
{
	int array[10] = {3, 77, 10, 7, 4, 9, 1, 8, 21, 33};
	int reverse[10] = {0};
	int i;

	printf("현재 숫자배열: ");

	for(i=0; i < 10; i++)
	{
		printf("%d ", array[i]);
	}

	for(i=0; i < 10; i++)
	{
		reverse[9-i] = array[i];
	}
	
	printf("reverse 숫자배열: ");

	for(i=0; i < 10; i++)
	{
		printf("%d ", reverse[i]);
	}


	return 0;
}
