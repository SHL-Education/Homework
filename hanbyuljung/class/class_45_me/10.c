#include<stdio.h>


int main(void)
{
	register unsigned int r0 asm("r0") = 0;
	register unsigned int r1 asm("r1") = 0;
	register unsigned int r2 asm("r2") = 0;
	register unsigned int r3 asm("r3") = 0;
	register unsigned int r4 asm("r4") = 0;
	register unsigned int r5 asm("r5") = 0;


	asm volatile("mov r2, #0x44, 8");
	asm volatile("mov r3, #0x200");
	asm volatile("umull r0, r1, r2,r3");



	printf("r1r0 = 0x%x %08x\n", r1,r0);

	return 0;
}
