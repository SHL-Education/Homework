#include<stdio.h>


int func(int a)
{
	a= a<<4;
	return a;
}
int main(void)
{
	int num =6;
	
	printf("num<<4=%d\n",func(num));
	return 0;

}
