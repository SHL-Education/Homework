#include <stdio.h>

int glob_val = 7;

void mult(void)
{
	glob_val *= 3;
}

void add(void)
{
	glob_val += 3;
}

int main(void)
{
	add();
	mult();
	printf("glob_val = %d\n", glob_val);

	return 0;
}


