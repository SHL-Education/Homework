#include<stdio.h>
int main(void)
{
	int arr[7] = {10,20,30};
	int *arr_p = arr;

	printf("현재값 = %d\n", *arr_p);
	printf("한칸 +이동 = %d\n",*(arr_p +1));
	printf("한칸 -이동 = %d\n",*(arr_p -1));
	printf("세칸 +이동 = %d\n",*(arr_p +3));

	return 0;
}
