#include <stdio.h>

void find_scaling(float xm, float xp, float ym, float yp,
				  float *xs, float *ys, float xmon, float ymon)
{
	*xs = xmon / xp;
	*ys = ymon / yp;
}

int main(void)
{
	float x_minus = -12.0;
	float x_plus = 12.0;
	float y_minus = -8.0;
	float y_plus = 8.0;
	float x_scale, y_scale;
	float x_mon = 800, y_mon = 600;

	find_scaling(x_minus, x_plus, y_minus, y_plus,
				 &x_scale, &y_scale, x_mon, y_mon);

	printf("x_scale = %f\n", x_scale);
	printf("y_scale = %f\n", y_scale);
}
