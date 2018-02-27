#include <stdio.h>

int rent_equip(int day, double money)
{
	int i, sum = 0;
	double rate = 1.0;

	if(day > 2)
		rate = 0.8;

	for(i = 0; i < day; i++)
		sum += money * rate;

	return sum;
}

int main(void)
{
	printf("money = %d\n", rent_equip(7, 37500));
	return 0;
}
