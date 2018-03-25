#include <stdio.h>
#include <math.h>

int calc_piece(float interval, float dx)
{
	return interval / dx;
}

float calc_int_4x_2_5x_1(float start, float end)
{
	int i, int_s, int_e;
	float sum = 0.0f;
	float temp = 0.0f;
	const float exp = 2.0;
	//const float dx = 0.000001f;
	//const float dx = 0.0000001f;
	//const float dx = 0.0000002f;
	//const float dx = 0.0000004f;
	//const float dx = 0.0000008f;
	//const float dx = 0.0000016f;
	//const float dx = 0.000002f;
	//const float dx = 0.0000025f;
	//const float dx = 0.000003f;
	//const float dx = 0.0000027f;
	//const float dx = 0.0000026f;
	//const float dx = 0.0000024f;
	//const float dx = 0.0000022f;
	//const float dx = 0.00000255f;
	//const float dx = 0.00000252f;
	//const float dx = 0.00000253f;
	//const float dx = 0.00000251f;
	//const float dx = 0.000002505f;
	const float dx = 0.000002504f;

	float dy = pow(dx, exp);

	printf("dx = %.3f\n", dx);
	printf("dy = %.6f\n", dy);

	int_s = 0.0f;
	int_e = calc_piece(end - start, dx);

	printf("int_e = %d\n", int_e);

	for (i = int_s; i < int_e; i++)
	{
		temp += dx;
		dy = 4 * pow(temp + start, exp) + 5 * (temp + start) + 1;
		sum += dx * dy;
	}

	printf("sum = %f\n", sum);

	return sum;
}

int main(void)
{
	float res;
	res = calc_int_4x_2_5x_1(1.0f, 3.0f);
	printf("res = %f\n", res);
	return 0;
}

/*

*/
