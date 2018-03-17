#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void init_mat(int (*M)[3])
{
	int i, j;

	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			M[i][j] = rand() % 4 + 1;
}

void print_mat(int (*M)[3])
{
	int i, j;

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("M[%d][%d] = %d\t", i, j, M[i][j]);
		}
		printf("\n");
	}
}

void mult_mat(int (*A)[3], int (*B)[3], int (*R)[3])
{
	int a = A[0][0], b = A[0][1], c = A[0][2],
		d = A[1][0], e = A[1][1], f = A[1][2],
		g = A[2][0], h = A[2][1], i = A[2][2],
		j = B[0][0], k = B[0][1], l = B[0][2],
		m = B[1][0], n = B[1][1], o = B[1][2],
		p = B[2][0], q = B[2][1], r = B[2][2];

	R[0][0] = a * j + b * m + c * p;
	R[0][1] = a * k + b * n + c * q;
	R[0][2] = a * l + b * o + c * r;
	R[1][0] = d * j + e * m + f * p;
	R[1][1] = d * k + e * n + f * q;
	R[1][2] = d * l + e * o + f * r;
	R[2][0] = g * j + h * m + i * p;
	R[2][1] = g * k + h * n + i * q;
	R[2][2] = g * l + h * o + i * r;
}

int main(void)
{
	int A[3][3] = {0};
	int B[3][3] = {0};
	int R[3][3] = {0};

	srand(time(NULL));

	init_mat(A);
	init_mat(B);

	printf("A:\n");
	print_mat(A);
	printf("\nB:\n");
	print_mat(B);

	mult_mat(A, B, R);

	printf("\nR:\n");
	print_mat(R);

	return 0;
}
