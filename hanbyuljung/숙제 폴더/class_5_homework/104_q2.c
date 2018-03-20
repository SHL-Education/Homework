#include<stdio.h>


int main(void)
{
		unsigned int a = 2004016;
		char *p=&a;
		
		printf("%p \n",&a);
		printf("%p \n",&a+0x01);
		printf("%p \n",&a+0x02);
		printf("%p \n",&a+0x03);
		printf("\n");
		printf("%c \n",&a);
		printf("%c \n",&a+0x01);
		printf("%c \n",&a+0x02);
		printf("%c \n",&a+0x03);

		return 0;
}

