#include<stdio.h>
#include<time.h>
#include<stdlib.h>


int find_NULL(int *arr)
{

	int i;
	int count = 0;
	printf("check 시작\n");
	for(i=0;i<100;i++){
		if(arr[i] == '\0')
			count ++;
	}
	return count;
}

int main(void)
{
	int a[100]={0};
	int i;
	srand(time(NULL));
	

	for(i=1;i<=100;i++){
		a[i-1]=rand()%4096+1;
		printf("%d ", a[i-1]);
		if(i%10 == 0)
			printf("\n");
	}
	printf("\n");
	printf("낭비된 공간의 수는 : %d \n",find_NULL(a));


	return 0;
}



