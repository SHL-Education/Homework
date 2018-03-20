#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//문제2: 1~4096 까지 무작위로 할당되어 배열에 저장되로록 프로그래밍 하시오.
//각 배열은 물건을 담을 수 있는 공간에 해당한다.
//앞서서 100 개의 공간에 물건들을 담았는데 공간의 낭비가 있을 수 있다.
//이 공간의 낭비가 얼마나 발생했는지 파악하는 프로그램을 작성하시오.
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

void insert(int *arr)
{
	int i;
	srand(time(NULL));
	for(i=0;i<100;i++)
		arr[i] = rand()%4096+1;  

}
void print(int *arr)
{
	int i;
	for(i=1; i<=100 ;i++)
	{
		printf("%d\t",arr[i-1]);
		if((i%10) == 0)
			printf("\n");
	}
	printf("\n");
}

int main(void)
{
	int a[100]={0};
	
	insert(a);
	print(a);
	printf("낭비된 값 : %d\n",find_NULL(a));
	

	return 0;
}
