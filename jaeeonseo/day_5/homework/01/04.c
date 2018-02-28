#include <stdio.h>

int main(void)
{
	int array[10] = {3, 77, 10, 7, 4, 9, 1, 8, 21, 33};
	int evenSum=0;
	int oddSum=0;
	int i;

	for(i=0; i < 10; i++)
	{
		if(!(i%2))
		{
			evenSum += array[i];
		}
		else
		{
			oddSum += array[i];
		}
	}

	printf("현재 숫자: ");
	
	for(i=0; i < 10; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n");
	
	printf("짝수의 합: %d\n", evenSum);
	printf("홀수의 합: %d\n", oddSum);

	return 0;
}
