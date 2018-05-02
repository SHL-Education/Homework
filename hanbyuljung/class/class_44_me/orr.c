#include<stdio.h>

void show_reg(unsigned int reg)
{
	int i;

	for(i=31; i>=0;)
		printf("%d", (reg>>i--)&1);
	printf("\n");
}

int main(void){
	register unsigned int r0 asm("r0")=0;
	register unsigned int r1 asm("r1")=0;
	register unsigned int r2 asm("r2")=0;
	register unsigned int r3 asm("r3")=0;
	register unsigned int r4 asm("r4")=0;
	register unsigned int r5 asm("r5")=0;

	r5 = 3;
	
	if(r0 == r1)
	{
		r3 = 44;
		asm volatile("orr r2,r3,r5");
	}

	show_reg(r2);
	return 0;
}


