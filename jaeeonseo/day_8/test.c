#include <stdio.h>
#include <stdlib.h>

void inputData(int **pArg)
{
	*pArg = (int *)malloc(sizeof(int));

	**pArg = 10;
} 



int main(void)
{
	int *pTest;

	inputData(&pTest);

	printf("%d\n", *pTest);

	return 0;
}
