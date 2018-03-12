#include <stdio.h>


void func(int (*a)[2])
{
	a[1][0]^=2;	
	a[1][1]^=2;
	a[1][2]^=2;
}

int (*a)[2] sapply(int (*a)[2],)
{

	func(a);
}

int main(void)
{
	int arr[2][3] = {{1,2,3},{1,2,3}};
	int i,j;
		
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\n", arr[i][j]);
		}
		printf("\n");
	}
	
	sapply(arr,func);
	return 0;
}
