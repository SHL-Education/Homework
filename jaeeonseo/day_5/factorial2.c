#include <stdio.h>

int fact(int num)
{
	int first = 1;
	while(num > 0)
	{
		first = first * num--;
	}
	return first;
}

int main(void)
{
	int result, fact_val;
	printf("계산할 팩토리얼을 입력하시오: ");
	scanf("%d", &fact_val);

	result = fact(fact_val);

	printf("%d번째 항의 수는 = %d\n", fact_val, result);

	return 0;
}
