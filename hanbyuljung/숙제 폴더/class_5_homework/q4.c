#include<stdio.h>

int change(int *arr,int len)
{
	int i=0;
	int even=0;
	int odd=0;
//	int res=0;
	
	for(i=0;i<len;i++){
		if(!(arr[i]%2))
				even+=arr[i];
		else
				odd+=arr[i];
	}
	return odd*even;
}

int main(void)
{
		int arr[]={3,77,10,7,4,9,1,8,21,33};
		int len= sizeof(arr)/4;
		int i;

		printf(" 결과 = %d\n",change(arr,len));
		
		return 0;
}
