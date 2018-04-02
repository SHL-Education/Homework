#include <stdio.h>
#include <math.h>

void func(int (*arr)[3])
{
	int i;

	for(i = 0; i < 3; i++)
		arr[1][i] = (int)powl(arr[1][i], 2);
}

void print_arr(int (*p)[3])
{
	int i, j;

	for(i = 0; i < 2; i++)
		for(j = 0; j < 3; j++)
			printf("p[%d][%d] = %d\n", i, j, p[i][j]);
	printf("\n");
}

void sapply(int (*p)[3], void (*f)(int (*)[3]))
{
	f(p);
}

int main(void)
{
	int A[2][3] = {{2, 4, 6}, {2, 4, 6}};

	print_arr(A);
	sapply(A, func);
	print_arr(A);

	return 0;
}
