#include<stdio.h>

int main(void)
{
	register unsigned int r0 asm("r0")=0;
	register unsigned int r1 asm("r1")=0;
	register unsigned int r2 asm("r2")=0;
	register unsigned int r3 asm("r3")=0;
	register unsigned int r4 asm("r4")=0;
	register unsigned int r5 asm("r5")=0;

	asm volatile("mov r1, #7");
	asm volatile("mov r2, #3");
	asm volatile("add r0,r1,r2,lsl #7");

	printf("r0 = 0x%x\n", r0);

	return 0;
}
