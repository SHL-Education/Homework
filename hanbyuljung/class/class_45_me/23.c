#include<stdio.h>

int my_func(int n1, int n2, int n3, int n4, int n5, int n6, int n7)
{
	return n1 + n2 + n3+ n4 +n5 + n6+ n7;

}

int main(void)
{
	int res, n1= 2, n2=3, n3=4, n4=5, n5=6, n6=7, n7=8;
	res = my_func(n1, n2, n3, n4, n5, n6, n7);
	printf("res = %d \n", res);

	return 0;
}
