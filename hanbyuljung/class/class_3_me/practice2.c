#include<stdio.h>


int func(int a)
{
	a= a>>3;
	return a;
}
int main(void)
{
	int num =55;
	
	printf("num<<4=%d\n",func(num));
	return 0;

}
