#include <stdio.h>

void make_fib(int *p, int last)
{
	int i = 2;

	for(; i < last; i++)
		p[i] = p[i - 2] + p[i - 1];
}

int get_even_odd_diff(int *p)
{
	int i, even = 0, odd = 0;

	for(i = 0; i < 27; i++)
	{
		if(p[i] % 2)
			odd += p[i];
		else
			even += p[i];
	}

	return odd - even;
}

int main(void)
{
	int res;
	int fib_arr[27] = {1, 1};
	make_fib(fib_arr, 27);
	res = get_even_odd_diff(fib_arr);
	printf("res = %d\n", res);

	return 0;
}
