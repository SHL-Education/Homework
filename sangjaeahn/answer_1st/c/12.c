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

	void (*ip)(int (*)[3], int (*)[3], int (*)[3]);	// 정수 배열 포인터 3개를 인자로 갖는 함수 포인터 선언.
	void (*fp)(float (*)[3], float (*)[3], float (*)[3]);	// 실수 배열 포인터 3개를 인자로 갖는 함수 포인터 선언. 
	ip = add_int;	// ip에 add_int 저장
	fp = add_float;	// fpdp add_float 저장

	srand(time(NULL));

	init_int_arr(A);	// 정수 행렬 초기화
	init_int_arr(B);
	ip(A, B, R);	// 정수 행렬 2개를 더해서 정수 행렬 R을 만듬.
	print_mat(R);	// R 행렬 출력

	init_float_arr(Af);	// 실수 행렬 초기화
	init_float_arr(Bf);
	fp(Af, Bf, Rf);	// 실수 행렬 2개를 더해서 실수 행렬 RF를 만듬.
	print_fmat(Rf);	// RF 행렬 출력.

	return 0;
}

/*
정수 3by3 행렬 2개와 실수 3by3 행렬 2개를 만들어서
정수행렬끼리 더하고, 실수행렬끼리 더해서 결과를 출력한다.
*/
