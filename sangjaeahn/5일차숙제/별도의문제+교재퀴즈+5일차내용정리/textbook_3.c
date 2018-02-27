#include <stdio.h>

int main(void)
{
	int array1[2][2]={{1,2},{3,4}}, array2[2][2]={{5,6},{7,8}};
	int result[2][2];
	
	result[0][0] = array1[0][0]*array2[0][0] + array1[0][1]*array2[1][0];
	result[0][1] = array1[0][0]*array2[0][1] + array1[0][1]*array2[1][1];
	result[1][0] = array1[1][0]*array2[0][0] + array1[1][1]*array2[1][0];
	result[1][1] = array1[1][0]*array2[0][1] + array1[1][1]*array2[1][1];

	printf("%d %d %d %d\n",result[0][0],result[0][1],result[1][0],result[1][1]);
	
	return 0;
}
