#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void init_mat(int (*M)[3])	// rand()함수를 통해 3by3 행렬을 초기화함.
{
	int i, j;

	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			M[i][j] = rand() % 4 + 1;	// 행렬의 원소를 1~4중에 랜덤으로 만듬.
}

void print_mat(int (*M)[3])	// 3by3 행렬을 이중 for문으로 출력함.
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
	int a = A[0][0], b = A[0][1], c = A[0][2],	// 행렬의 각각의 원소를 모두 문자로 치환함.
		d = A[1][0], e = A[1][1], f = A[1][2],
		g = A[2][0], h = A[2][1], i = A[2][2],
		j = B[0][0], k = B[0][1], l = B[0][2],
		m = B[1][0], n = B[1][1], o = B[1][2],
		p = B[2][0], q = B[2][1], r = B[2][2];

	R[0][0] = a * j + b * m + c * p;	// 치환된 문자끼리 곱해서 행렬 R을 만듬.
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

	init_mat(A);	// 3by3 행렬 A 초기화
	init_mat(B);	// 3by3 행렬 B 초기화

	printf("A:\n");
	print_mat(A);	// 행렬 A 출력
	printf("\nB:\n");
	print_mat(B);	// 행렬 B 출력

	mult_mat(A, B, R);	// 행렬 A,B 를 곱해서 행렬 R을 만듬.

	printf("\nR:\n");
	print_mat(R);	// 행렬 R 출력

	return 0;
}

/*
3by3 행렬 2개를 랜덤으로 초기화 시키고, 두 행렬을 곱해서 결과값을 출력함.

함수에서 이중배열의 주소를 인자로 받을 때에는,
이중포인터를 쓰는 것이 아니라 배열 포인터를 사용해야 한다
이중포인터를 사용하면 1중배열의 크기를 모르기 때문이다.
*/
