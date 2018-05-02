#include<stdio.h>

int main(void)
{
	register unsigned int r0 asm("r0");
	register unsigned int r1 asm("r1");
	register unsigned int r2 asm("r2");
	register unsigned int r3 asm("r3");
	register unsigned int r4 asm("r4");
	register unsigned int r5 asm("r5");

	r1=77;
	r2=37;
	r3= 34;
	r5= 3;

	if(r2<=r1)
		asm volatile("rsble r4, r5, #5");
	printf("r4 = %d\n", r4);
	return 0;
}

	
