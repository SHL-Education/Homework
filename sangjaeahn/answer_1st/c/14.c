#include <stdio.h>

int find_series(int *data, int find)
{
	int i = 2;

	for(; i < find; i++)
		data[i] = data[i - 2] + data[i - 1]; // 피보나치 수열의 방정식	

	return data[i - 1]; // 21번째 항을 반환함.
}

int main(void)
{
	int res;
	int data[24] = {1, 4};	// 처음 두항을 1과 4로 함.

	res = find_series(data, 23);
	printf("res = %d\n", res);

	return 0;
}

/*
피보나치 수열을 만들고 21번째항을 출력함.
*/
