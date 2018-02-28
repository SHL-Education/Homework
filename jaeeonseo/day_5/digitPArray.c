#include <stdio.h>

void arr_print(int arr[])
{
	int i;
	for(i = 0; i < 3; i++)
		printf("%4d\n", arr[i]);

}


int main(void)
{
	int arr[3] = {3, 33, 333};
	arr_print(arr);
	
	return 0;
}
