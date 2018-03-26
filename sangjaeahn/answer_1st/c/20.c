#include <stdio.h>
#include <math.h>

int get_bit_order(int x, int order)
{
	return x & ~(int)(powl(2, order) - 1);	// 27번째 bit보다 상위 비트는 모두 1로 만듬.
}

int main(void)
{
	int res, x = 394217728;
	printf("x = 0x%x, x(int) = %d\n", x, x);
	res = get_bit_order(x, 27);
	printf("res = 0x%x, res(int) = %d\n", res, res);
	return 0;
}

/*
어떠한 수를 2^27 단위로 만듬.
*/
