#include<stdio.h>

int main(void)
{
	register unsigned int r0 asm("r0")=0;
	register unsigned int r1 asm("r1")=0;
	register unsigned int r2 asm("r2")=0;
	register unsigned int r3 asm("r3")=0;
	register unsigned int r4 asm("r4")=0;
	register unsigned int r5 asm("r5")=0;

	asm volatile("mov r0, #0xff, 8");
	asm volatile("mov r1, #0xf");
	asm volatile("add r2, r1, r0");

	printf("r2 = 0x%x\n", r2);

	return 0;
}

