#include <stdio.h>

// int (*)(int)
int t1(int a)
{
	printf("t1 function\n");
	return a * 3;
}

// int (*)(int) tp1(int (*p)(int))
// int (* tp1(int (*p)(int)))(int)
int (* tp1(int (*p)(int)))(int)
{
	printf("tp1 function\n");
	p(3);
	return p;
}

// int (*)(int) (*)(int (*p)(int)) tpp1 (int a, int b)
// int (*)(int) (* tpp1 (int a, int b))(int (*p)(int))
// int (* (* tpp1 (int a, int b))(int (*p)(int)))(int)
int (* (* tpp1(int a, int b))(int (*p)(int)))(int)
{
	printf("tpp1 function a = %d, b = %d\n", a, b);
	return tp1;
}

int main(void)
{
	int num;
	num = tpp1(3, 7)(t1)(33);
	printf("num = %d\n", num);
	return 0;
}
