#include <stdio.h>

void print_seven_series(int num)
{
	printf("res = %d\n", num * 7);
}

int main(void)
{
	int num;
	scanf("%d", &num);
	print_seven_series(num);
	return 0;
}
