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
	int size = 4096;
	int num=1;
	srand(time(NULL));
	
	printf("사이즈를 선택하시오\n");
	printf("사이즈는 4096의 배수입니다.\n");
	do{
		printf(" 131072 까지 가능합니다. 몇배를 할지 선택해 주세요.\n");
		scanf("%d",&num); 

	}while((size*num)>=131072);


	for(i=1;i<=100;i++){
		a[i-1]=rand()%(size*num)+1;
		printf("%d ", a[i-1]);
		if(i%10 == 0)
			printf("\n");
	}
	printf("\n");
	printf("낭비된 공간의 수는 : %d \n",find_NULL(a));


	return 0;
}



