#include <stdio.h>

int main(void)
{
	char a=127, b=-128;
	a++;
	b--;
	printf("Overflow: %d", a);
	printf("Underflow: %d", b);

	return 0;
}
