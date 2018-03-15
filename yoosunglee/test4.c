#include<stdio.h>
int main(void)
{
int arr[3][3][3];
int i,j,k, num =1;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				
			arr[i][j][k] = num;
			printf("arr[%d][%d][%d] = %d\n", i,j,k,arr[i][j][k]);
			num ++;
			}
		}
	}
return 0;
}
