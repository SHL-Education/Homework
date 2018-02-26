#include <stdio.h>


float discount(int days);
int price(int days);

int main(void)
{
	int days = 7;
	int prices;
	
	prices = price(days);
	
	if(days >= 3)
	{
		prices = discount(prices);
	}

	printf("price is %d\n", prices);

	return 0;
}

int price(int days)
{
	return 37500 * days;
}

float discount(int price)
{	
	return price * 0.2;
}
