#include <stdio.h>

void multipleMatrix(int a[][3], int b[][3])
{
	int multiple_matrix[3][3] = {0};
	int result;
	int i, j, k;

	//행렬 곱셈
	
	for(i=0; i <3; i++)
	{
		for(j=0; j <3; j++)
		{
			result = a[i][j]*b[j][i];
		}
		
		multiple_matrix[i][k] = result;
		k++;

		if(k >2)
		{
		   k=0;
		}
	}

	printf("행렬 a[3][3]*b[3][3] = \n");

	for(i=0; i<3; i++)
	{
		for(j=0; j <3; j++)
		{
			printf("%d " , multiple_matrix[i][j]);
		}

		printf("\n");
	}

	printf("\n");
}

void addMatrix(int a[][3], int b[][3])
{

	int add_matrix[3][3] = {0};
	int result;	
	int i, j;

	//행렬 덧셈
	
	for(i=0; i <3; i++)
	{
		for(j=0; j <3; j++)
		{
			add_matrix[i][j] = a[i][j]+b[i][j];
		}
	}
		
	printf("행렬 a[3][3]+b[3][3] = \n");

	for(i=0; i<3; i++)
	{
		for(j=0; j <3; j++)
		{
			printf("%d " , add_matrix[i][j]);
		}

		printf("\n");
	}

	printf("\n");
}

void minusMatrix(int a[][3], int b[][3])
{

	int minus_matrix[3][3] = {0};
	int result;	
	int i, j;

	//행렬뺄셈
	
	for(i=0; i <3; i++)
	{
		for(j=0; j <3; j++)
		{
			minus_matrix[i][j] = a[i][j]-b[i][j];
		}
	}
		
	printf("행렬 a[3][3]-b[3][3] = \n");

	for(i=0; i<3; i++)
	{
		for(j=0; j <3; j++)
		{
			printf("%d " , minus_matrix[i][j]);
		}

		printf("\n");
	}

	printf("\n");

}

void divisionMatrix(int a[][3], int b[][3])
{
	int division_matrix[3][3] = {0};
	int result;
	int i, j;

	//행렬 나눗셈 
	
	for(i=0; i <3; i++)
	{
		for(j=0; j <3; j++)
		{
			division_matrix[i][j] = a[i][j]/b[i][j];
		}
	}
		
	printf("행렬 a[3][3]/b[3][3] = \n");

	for(i=0; i<3; i++)
	{
		for(j=0; j <3; j++)
		{
			printf("%d " , division_matrix[i][j]);
		}

		printf("\n");
	}

	printf("\n");
}



int main(void)
{
	int a_matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int b_matrix[3][3] = {{2, 4, 8}, {2, 4, 8}, {2, 4, 8}};
	int i, j, k;
	

	printf("행렬 a:\n");
	
	for(i=0; i <3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%d ", a_matrix[i][j]);
		}

		printf("\n");
	}


	printf("행렬 b:\n");
	
	for(i=0; i <3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%d ", b_matrix[i][j]);
		}

		printf("\n");
	}

	printf("\n");

	multipleMatrix(a_matrix, b_matrix);
	addMatrix(a_matrix, b_matrix);
	minusMatrix(a_matrix, b_matrix);
	divisionMatrix(a_matrix, b_matrix);
	

	return 0;
}
