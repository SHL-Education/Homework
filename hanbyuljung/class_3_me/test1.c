#include<stdio.h>

int main(void)
{

	char a= 127, b=-128;

	a++;
	b--;

	printf("Overflow:%d\n",a);
	printf("Underflow:%d=\n",b);
	return 0;



}
