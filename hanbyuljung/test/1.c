#include<stdio.h>

int main(void)
{
	int num =7 , num2=3;
	int *pn = &num;
	int **ppn = &pn;
	int ***pppn=&ppn;
	pn = &num2;
	printf("***pppn=%d\n",***pppn);

	return 0;

}
