#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//문제: 1~4096 까지 무작위로 할당되어 배열에 저장되로록 프로그래밍 하시오.
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

	return 0;
}
