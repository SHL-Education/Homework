#include<stdio.h>
#include<stdlib.h>


int main (void)
{
	int *num_ptr  = (int *)calloc(2, sizeof(int));

	printf("Input Integer:");
	scanf("%d%d",&num_ptr[0],&num_ptr[1]);

	if (num_ptr != NULL)
			printf("Integer =%d, %d \n", num_ptr[0], num_ptr[1]);

	free(num_ptr);


	return 0;

}
