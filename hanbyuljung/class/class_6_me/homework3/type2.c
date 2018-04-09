#include<stdio.h>

typedef int INT[5];


int main(void)
{

	int i;
	INT arr = {1,2, 3, 4,5};

	for(i=0;i <5;i++)
		printf("arr[%d]=%d\n",i, arr[i]);

	return 0;
}
