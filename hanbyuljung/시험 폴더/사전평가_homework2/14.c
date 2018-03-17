#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	char a[]="TI Cortex-R5F Safety MCU is very good to Real-Time System.";

	printf("같곳의 주소 값은 %p\n",strstr(a,"Safety MCU"));
	
	return 0 ;
}
