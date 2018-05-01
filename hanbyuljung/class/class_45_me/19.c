#include<stdio.h>


int main(void)
{
	int i;
	unsigned int test_arr[5]={0};

	register unsigned int *r0 asm("r0")=0;
	register unsigned int r1 asm("r1")=0;
	register unsigned int r2 asm("r2")=0;
	register unsigned int r3 asm("r3")=0;
	register unsigned int r4 asm("r4")=0;
	register unsigned int r5 asm("r5")=0;

	r0 = test_arr;					

	asm volatile("mov r1, #0x3");
	asm volatile("mov r2,r1,lsl#2");
	asm volatile("mov r4, #0x2");
	asm volatile("add r3,r1, r2,lsl r4");
	asm volatile("stmia r0!,{r1,r2,r3}");	
	asm volatile("str r4, [r0]");


	for(i=0; i<5;i++)
		printf("test_arr[%d]= %d\n", i,test_arr[i]);

	return 0;
}
