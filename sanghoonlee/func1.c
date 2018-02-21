#include <stdio.h>

int myfunc(int num)
{
	// return num * 2;
	return num + 3;
	// return num << 1;
}

int main(void)
{
	int num = 3, res;
	res = myfunc(num);
	printf("res = %d\n", res);

	return 0;
}
