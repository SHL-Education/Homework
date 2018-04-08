#include<stdio.h>


int funcAND(int a,int b)
{

	a= a&b;
	return a;
}

int funcOR(int a,int b)
{
	
	a= a|b;
	return a;
}

int funcXOR(int a,int b)
{
	a= a^b;
	return a;
}

int main(void)
{
	int num1 = 21;
	int num2 = 31;
	
	printf("AND=%d\n",funcAND(num1,num2));
	printf("OR=%d\n",funcOR(num1,num2));
	printf("XOR=%d\n",funcXOR(num1,num2));
	return 0;

}
