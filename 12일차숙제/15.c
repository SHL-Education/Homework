/*
문제:배열의 값들 중에 가장 빈도수가 높은 3개의 숫자를 찾아 출력하시오!
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct __array{
	int num[153];
	int count[153];
}array;

int find_max(array* arr, int len)
{
	int i, max = arr->count[0];

	for(i=0;i<len;i++)
	{
		if(max < arr->count[i])
		{
			max = arr->count[i];
		}
	}
	
	for(i=0;i<len;i++)
	{
		if(max == arr->count[i])
		{
			arr->count[i] = 0;
			break;
		}
	}		

	return arr->num[i];
}

int main(void)
{
	int a[153] = {2400,2400,2400,2400,2400,2400,2400,2400,2400,2400,2400,2400,2400,2400,2400,2400,2400,2400,2400,2400,2400,2400,2400,2400,2400,2400,2400,2400,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,234,345,26023,346,345,234,457,3,1224,34,646,732,5,4467,45,623,4,356,45,6,123,3245,6567,234,567,6789,123,2334,345,4576,678,789,1000,978,456,234756,234,4564,3243,876,645,534,423,312,756,235,75678};
	int i=0, j=0, max1, max2, max3;

	array *array1 = (array *)malloc(sizeof(array));
	
	for(i=0;i<153;i++)
	{
		array1->num[i] = 0;
		array1->count[i] = 0;
	}

	i=0;
	
	while(i <= 153)
	{
		while(array1->num[j])
		{
			if(array1->num[j] == a[i])
			{
				array1->count[j]++;
				break;
			}
	
			j++;
		}
	
		if(!array1->num[j])
		{	
			array1->num[j] = a[i];
			array1->count[j]++;
		}
		j=0;
		i++;
	}

	max1 = find_max(array1, sizeof(array1->count)/sizeof(int));
	max2 = find_max(array1, sizeof(array1->count)/sizeof(int));
	max3 = find_max(array1, sizeof(array1->count)/sizeof(int));

	
	printf("%d\n", max1);
	printf("%d\n", max2);
	printf("%d\n", max3);
	
	return 0;
}

/*결과값

5000
2400
500

*/
