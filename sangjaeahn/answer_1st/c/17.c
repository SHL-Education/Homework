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

	print_arr(A);	// 이중 배열 A의 원소를 모두 출력
	sapply(A, func);	// func함수와 A배열을 sappy함수에서 인자로 받음.
	print_arr(A);	// A배열의 원소들을 모두 출력함.

	return 0;
}

/*
sapply : int 3개의 배열에 대한 포인터와
int 3개 배열의 포인터를 인자로하는 함수에 대한 포인터를 인자로 하는 함수

print_arr, func : int 3개의 배열에 대한 포인터를 인자로하는 함수
*/
