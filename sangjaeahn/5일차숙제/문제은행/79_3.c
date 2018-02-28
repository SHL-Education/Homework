#include <stdio.h>

#define index 10

int main(void)
{
	int array[index] = {3,77,10,7,4,9,1,8,21,33};
	int reverse_array[index]={0,};
	int i;

	for(i=0;i<index;i++)
	{
		reverse_array[i] = array[index-1-i];
	}
	
	for(i=0;i<index;i++)
	{
		printf("%d ",reverse_array[i]);
	}
	printf("\n");
	return 0;
}
