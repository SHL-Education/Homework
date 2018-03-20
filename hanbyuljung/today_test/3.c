#include<stdio.h>
float fuc(int ADC, int voltage_max , int mcu_bit){

	return (float)ADC*(float)voltage_max/(float)mcu_bit;
}

int main(void)
{
	int ADC = 2077;
	int voltage_max = 5;
	int mcu_bit = 4096;
	float res;

	printf("현재 전압 값: 2077:4096 = x : 5v\n");
	res = fuc(ADC,voltage_max,mcu_bit);
	printf("x = %.2f\n", res);

	return 0;
}
