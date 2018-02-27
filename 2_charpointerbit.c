#include<stdio.h>
int main(void)
{
	int num = 2004016;
	char * charbit = num;
	int res = 0;
	res = *charbit <<1;
	printf("%d",res);
	return 0;
}
