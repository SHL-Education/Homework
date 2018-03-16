#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int* insert(int arr[], int index)
{
	int i;

        for(i=0;i<index;i++)
        {
                arr[i] = rand() % 4097;
                if(!arr[i])
                {
                        arr[i]++;
                }
        }

	return arr;
}

void print_arr(int arr[], int index)
{
	int i;
	
	for(i=0;i<index;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(void)
{
	int arr[100];
	int index;
	
	srand(time(NULL));
	index = rand()%100;

	insert(arr, index);
	print_arr(arr, index);

	return 0;
}
