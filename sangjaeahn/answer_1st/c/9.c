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

// int (*)(int) (*) (int (*p)(int)) tpp1 (int a, int b)
// int (*)(int) (* tpp1 (int a, int b)) (int (*p)(int))
// int (* (* tpp1 (int a, int b)) (int (*p)(int))(int)


/*
tpp1 : int를 인자로 하고 int를 반환하는 함수의 포인터를 반환하고, 
       int를 인자로 하고 int를 반환하는 함수의 포인터를 인자로하는 함수의 포인터를 반환하고,
       / int 2개를 인자로 하는 함수

tp1 : int를 인자로 하고 int를 반환하는 함수의 포인터를 반환하고,
      int를 인자로 하고 int를 반환하는 함수의 포인터를 인자로 하는 함수

t1 : int를 인자로하고 int를 반환하는 함수
*/
