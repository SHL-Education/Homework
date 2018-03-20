#include<stdio.h>


void print(int (*arr)[3])
{
	int i, j;
	printf("\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++){
			printf("%4d",arr[i][j]);
		}
		printf("\n");
	}
}


int main(void)
{

	int a[3][3]={0};
	int b[3][3]={0};
	int res[3]={0};
	int i, j,num;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("3*3 행렬의 %d*%d 의 값을 입력하시오. \n",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("3*3 행렬의 %d*%d 의 값을 입력하시오. \n",i,j);
			scanf("%d",&b[i][j]);
		}
	}

	print(a);
	print(b);
	
	for(i = 0;i<3;i++)
	{
		for(j=0;j<3;j++)
			res[i]+=a[i][j]*b[j][i];
		printf("\n");
	}
	for(i=0; i<3;i++)
		printf("%3d, ", res[i]);
	printf("\n");
}

