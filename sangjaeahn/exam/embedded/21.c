#include <stdio.h>

int main(void)
{
	char c;
	
	scanf("%c", &c);
	c ^= 32;
	
	printf("%c\n", c);
	return 0;
}
