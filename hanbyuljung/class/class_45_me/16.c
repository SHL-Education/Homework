#include<stdio.h>

char test[] = "HelloARMddd";

void show_reg(unsigned int reg)
{
	int i;

	for(i = 31;i>=0;)
		printf("%d", (reg>>i--)&1);
	printf("\n");
}

int main(void)
{
	register unsigned int r0 asm("r0")=0;
	register char *r1 asm("r1")=NULL;
	register unsigned int *r2 asm("r2")=NULL;
	register unsigned int r3 asm("r3")=0;
	register unsigned int r4 asm("r4")=0;
	register char *r5 asm("r5")=NULL;


	r1 = test;					// r1 = test

	asm volatile("mov r2, #0x5");
	//asm volatile("ldr r0, [r1, r2]!");	

	asm volatile("ldr r5, [r1, r2]!");	// strb r0 ,[r1,#5]
	printf("test = %s, r1 = %s, r5 = %d\n",test,r1,r5);

	return 0;
}
