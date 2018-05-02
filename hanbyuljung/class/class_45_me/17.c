#include<stdio.h>

unsigned int arr[5] = {1,2,3,4,5};

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
	register unsigned int *r1 asm("r1")=NULL;
	register unsigned int *r2 asm("r2")=NULL;
	register unsigned int r3 asm("r3")=0;
	register unsigned int r4 asm("r4")=0;
	register unsigned int r5 asm("r5")=0;

	r1 = arr;					

	asm volatile("mov r2, #0x4");
	asm volatile("ldr r0, [r1],r2");	

	printf("r0 = %u, r1 = %u\n",r0, *r1);

	return 0;
}
