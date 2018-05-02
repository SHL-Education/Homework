#include<stdio.h>

void show_reg(unsigned int reg)
{
	int I;

	for(I =31;I>=0;)
		printf("%d",(reg>>I--)&1);
	printf("\n");
}

int main(void)
{
	register unsigned int r0 asm("r0");
	register unsigned int r1 asm("r1");
	register unsigned int r2 asm("r2");
	register unsigned int r3 asm("r3");
	register unsigned int r4 asm("r4");
	register unsigned int r5 asm("r5");

	r1 = 34;
	r2 = 37;
	r5 = 3;

	asm volatile("and r0, r1,r2");

	show_reg(r0);
	return 0;
}


