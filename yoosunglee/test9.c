#include<stdio.h>
int main(void)
{
	int arr1[3][2];
	int arr2[3][3];
	int arr3[3][4];

	printf("%p\t %p\t %p\n",arr1,arr1+1,arr1+2);
	printf("%p\t %p\t %p\n",arr2,arr2+1,arr2+2);
	printf("%p\t %p\t %p\n",arr3,arr3+1,arr3+2);

	return 0;
}
