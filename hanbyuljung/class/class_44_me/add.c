#include<stdio.h>

int main(void)
{
	register unsigned int r0 asm("r0");
	register unsigned int r1 asm("r1");
	register unsigned int r2 asm("r2");

	r1 = 77;
	r2 = 37;

	asm volatile("add r0, r1, r2");

	printf("r0 = %d\n", r0);
	return 0;
}

