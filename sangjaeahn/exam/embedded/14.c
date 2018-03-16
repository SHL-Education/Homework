#include <stdio.h>

int main(void)
{
	int arr[23] = {1,4,0,};
	int i;
	
	for(i=2;i<23;i++)
	{
		arr[i] = arr[i-2] + arr[i-1];
	}
	
	printf("23번째 숫자는 %d 입니다.\n", arr[22]);
	return 0;
}
