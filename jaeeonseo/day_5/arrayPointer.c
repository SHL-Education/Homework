#include <stdio.h>

int main(void)
{
	int i, j, n1, n2, n3;
	int a[2][2] = {{10, 20}, {30, 40}};
	int *arr_ptr[3] = {&n1, &n2, &n3};
	int (*p)[3] = a;

	for(i=0; i < 3; i++)
	{
		*arr_ptr[i] = i;
	}
	
	for(i=0; i <3; i++)
	{
		printf("n%d = %d\n", i, *arr_ptr[i]);
	}

	for(i=0; i <2; i++)
	{
		printf("p[%d] = %d\n", i, *p[i]);
	}

	return 0;
}
