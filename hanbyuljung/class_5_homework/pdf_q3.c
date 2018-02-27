#include<stdio.h>

void cal(int **a,int **b)
{
	int i,j,res[2];	
	for(i=0;i<2;i++){
			for(j=0;j<2;j++){
				res[i]+=a[i][j]*b[j][i];
			}
			printf("\n");
	}
	for(i=0;i<2;i++)
			printf("%3d",res[i]);
	
}

int main(void)
{
	int a[2][2]={{0},{0}};
	int b[2][2]={{0},{0}};
	int i, j,num;

	for(i=0;i<2;i++){
			for(j=0;j<2;j++){
					printf("2*2 행렬의 1번 행렬 %d*%d 의 값을 입력하시오. \n",i,j);
					scanf("%d",&a[i][j]);
			}
	}

	for(i=0;i<2;i++){
			for(j=0;j<2;j++){
					printf("2*2 행렬의 1번 행렬 %d*%d 의 값을 입력하시오. \n",i,j);
					scanf("%d",&b[i][j]);
			}
	}
	printf("1번 행렬은\n");
	for(i=0;i<2;i++){
			for(j=0;j<2;j++){
					printf("%4d\n",a[i][j]);
			}
			printf("\n");
	}

	printf("2번 행렬은\n");

	for(i=0;i<2;i++){
			for(j=0;j<2;j++){
					printf("%4d\n",b[i][j]);
			}
			printf("\n");
	}

	return 0;

}
