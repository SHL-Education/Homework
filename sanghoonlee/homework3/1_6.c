#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void init_2x2_matrix(int (*mat)[2])
{
	int i, j;

	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			// 1 ~ 4
			mat[i][j] = rand() % 4 + 1;
		}
	}
}

void print_mat(int (* mat)[2])
{
	int i, j;

	printf("mat:\n");

	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("%4d", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void add_2x2_matrix(int (*A)[2], int (*B)[2], int (*R)[2])
{
	int i, j;

	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			R[i][j] = A[i][j] + B[i][j];
		}
	}
}

void sub_2x2_matrix(int (*A)[2], int (*B)[2], int (*R)[2])
{
	int i, j;

	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			R[i][j] = A[i][j] - B[i][j];
		}
	}
}

void mult_2x2_matrix(int (*A)[2], int (*B)[2], int (*R)[2])
{
	/* a b   e f
	   c d   g h

	   ae + bg	af + bh
	   ce + dg	cf + dh */
	R[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
	R[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
	R[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
	R[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
}

int main(void)
{
	int mat1[2][2] = {0};
	int mat2[2][2] = {0};
	int res[2][2] = {0};

	// It's for use rand() function.
	srand(time(NULL));

	init_2x2_matrix(mat1);
	print_mat(mat1);

	init_2x2_matrix(mat2);
	print_mat(mat2);

	add_2x2_matrix(mat1, mat2, res);
	print_mat(res);

	sub_2x2_matrix(mat1, mat2, res);
	print_mat(res);

	mult_2x2_matrix(mat1, mat2, res);
	print_mat(res);

	return 0;
}
