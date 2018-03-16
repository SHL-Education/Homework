#include <stdio.h>
#include <math.h>

int get_bit_order(int x, int order)
{
	return x & ~(int)(powl(2, order) - 1);
}

int main(void)
{
	int res, x = 394217728;
	printf("x = 0x%x, x(int) = %d\n", x, x);
	res = get_bit_order(x, 27);
	printf("res = 0x%x, res(int) = %d\n", res, res);
	return 0;
}
