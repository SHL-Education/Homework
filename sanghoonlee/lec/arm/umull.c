#include <stdio.h>

int main(void)
{
		register unsigned int r4 asm("r4") = 0;
		register unsigned int r5 asm("r5") = 0;
		register unsigned int r6 asm("r6") = 0;
		register unsigned int r7 asm("r7") = 0;
		register unsigned int r8 asm("r8") = 0;
		register unsigned int r9 asm("r9") = 0;

		asm volatile("mov r8, #0x44, 8");
		asm volatile("mov r9, #0x200");
		asm volatile("umull r4, r5, r8, r9");

		printf("r1r0 = 0x%x %08x\n", r5, r4);

		return 0;
}
