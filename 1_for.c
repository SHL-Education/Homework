#include <stdio.h>

// input: first - day, second - 37500
int borrow_equip(int day, double money)
{
	int i = 0, res = 0;
	double rate = 1.0;
	double tmp = 0;

	if(day >= 3)
	{
		rate = 0.8;
		tmp = money * rate;
	}

	for(i = 0; i < 7; i++)
	{
		res += tmp;
		printf("res = %d\n", res);
	}

	return res;
}

int main(void)
{
	printf("res = %d\n", borrow_equip(7, 37500));
	return 0;
}






