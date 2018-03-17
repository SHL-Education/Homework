#include<stdio.h>

void change(int *arr,int *arr2,int len)
{
	int i=0;
	//int len= sizeof(arr)/4;
	
	printf("배열의 길이는 몇인가? %d\n",len);
	for(i=0;i<len;i++){
			arr2[len-i-1]=arr[i];
	}
}
void print_arr(int *arr2,int len)
{
		int i;	
		//int len= sizeof(arr2)/4;

		printf("배열의 길이는 몇인가? %d\n",len);
		printf("배열의 요소는?\n");
		for(i =0;i<len;i++)
				printf("%4d",arr2[i]);
}

int main(void)
{
		int arr[]={3,77,10,7,4,9,1,8,21,33};
		int len= sizeof(arr)/4;
		int arr2[len];
		int i;

		printf("배열의 길이는 몇인가? %d\n",len);
		change(arr,arr2,len);
		print_arr(arr2,len);
		printf("\n");
		
		return 0;
}
