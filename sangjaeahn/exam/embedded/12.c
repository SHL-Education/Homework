#include <stdio.h>

void print_add_int(int **arr)
{
        int i,j;

        for(i=0;i<3;i++)
        {
                for(j=0;j<3;j++)
                {
                        printf("%d ", *(*(arr+i)+j));
                }
                printf("\n");
        }
}

void print_add_float(float **arr)
{
        int i,j;

        for(i=0;i<3;i++)
        {
                for(j=0;j<3;j++)
                {
                        printf("%f ", *(*(arr+i)+j));
                }
       		printf("\n");
	 }
}

int** add_int(int arr1[3][3], int arr2[3][3])
{
	int arr[3][3];
	int i,j;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			arr[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
	
	return arr;
}

float** add_float(float arr1[3][3], float arr2[3][3])
{
	float arr[3][3];
	int i,j;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			arr[i][j] = arr1[i][j] + arr2[i][j];	
		}
	}

	return arr;
}

int main(void)
{
	int arr1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};	
	int arr2[3][3] = {{10,20,30},{40,50,60},{70,80,90}};
	float arr3[3][3] = {{1.5,2.5,3.5},{1.6,2.6,3.6},{1.7,2.7,3.7}};
	float arr4[3][3] = {{10.5,20.5,30.5},{10.6,20.6,30.6},{10.7,20.7,30.7}};

	int **int_arr;
	float **float_arr;
			
	int_arr = add_int(arr1, arr2);
	float_arr = add_float(arr3, arr4);
	
	print_add_int(int_arr);
	print_add_float(float_arr);	

	return 0;
}
