#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *ptr = (int *)malloc(sizeof(int)*10);
	
	printf("ptr = %p\n", ptr);
	printf("ptr value = %d\n", *ptr);

 	*ptr = 27;

	printf("ptr value = %d\n", *ptr);

	return 0;
}
