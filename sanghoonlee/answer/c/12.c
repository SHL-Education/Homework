#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void add_float(float (*A)[3], float (*B)[3], float (*R)[3])
{
	int i, j;

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			R[i][j] = A[i][j] + B[i][j];
			printf("R[%d][%d] = %f\t", i, j, R[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void init_float_arr(float (*M)[3])
{
	int i ,j;

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			M[i][j] = (rand() % 30 + 1.0) / 10.0;
			printf("M[%d][%d] = %f\t", i, j, M[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void print_fmat(float (*M)[3])
{
	int i, j;

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("M[%d][%d] = %f\t", i, j, M[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


void add_int(int (*A)[3], int (*B)[3], int (*R)[3])
{
	int i, j;

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			R[i][j] = A[i][j] + B[i][j];
			printf("R[%d][%d] = %d\t", i, j, R[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void init_int_arr(int (*M)[3])
{
	int i ,j;

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			M[i][j] = rand() % 3 + 1;
			printf("M[%d][%d] = %d\t", i, j, M[i][j]);
		}
		printf("\n");
	}
	printf("\n");
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
	printf("\n");
}

int main(void)
{
	int A[3][3] = {0};
	int B[3][3] = {0};
	int R[3][3] = {0};

	float Af[3][3] = {0};
	float Bf[3][3] = {0};
	float Rf[3][3] = {0};

	void (*ip)(int (*)[3], int (*)[3], int (*)[3]);
	void (*fp)(float (*)[3], float (*)[3], float (*)[3]);
	ip = add_int;
	fp = add_float;

	srand(time(NULL));

	init_int_arr(A);
	init_int_arr(B);
	ip(A, B, R);
	print_mat(R);

	init_float_arr(Af);
	init_float_arr(Bf);
	fp(Af, Bf, Rf);
	print_fmat(Rf);

	return 0;
}
