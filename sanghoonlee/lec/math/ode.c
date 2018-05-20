#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SAMPLE_TIME		0.001f

#define LEFT			0
#define RIGHT			1

void init_sample_x(float *data)
{
	int i;

	for(i = 0; i < 10001; i++)
		data[i] = -5 + SAMPLE_TIME * i;

	//printf("Check Final: %f\n", data[10000]);
}

void init_sample_data(float *data, float *sam_x)
{
	int i;

	for(i = 0; i < 10001; i++)
		data[i] = 3 * exp(-pow(sam_x[i], 2.0));

	//printf("Check Mid Val: %f\n", data[5000]);
}

void calc_derivative(float *data, float *y)
{
	int i;

	for(i = 0; i < 10000; i++)
		data[i] = (y[i + 1] - y[i]) / SAMPLE_TIME;
}

void print_arr(float *data, int num)
{
	int i;

	for(i = 0; i < num; i++)
	{
		printf("data[%d] = %17.15f", i, data[i]);

		if(!(i % 3))
			printf("\n");
		else
			printf(", ");
	}
}

int find_prime_idx(char *expr, char *dch)
{
	int i;

	for(i = 0; expr[i]; i++)
		if(expr[i] == '\'')
		{
			*dch = expr[i - 1];
			return i;
		}
}

bool seperate_non_depend(char *expr, int idx, char dch, char *nd)
{
	bool div_flag;
	int i, j = 0;

	for(i = idx + 1; expr[i] != dch; i++)
	{
		if(expr[i] == ' ' || expr[i] == '=')
			continue;
		else
			nd[j++] = expr[i];

		if(expr[i] == '/')
			div_flag = true;
	}

	return div_flag;
}

void integral(char *lr, char *nd, int lr_choice, bool div_flag)
{
	int i, j = 0, k = 0;
	int num, exponent;
	float coef;

	char digit[32] = {0};
	char var;

	if(lr_choice == RIGHT)
		goto right;

	for(i = 0; nd[i]; i++)
	{
		if(nd[i] > 0x61 && nd[i] < 0x7A)
		{
			var = nd[i];
			if(nd[i + 1] == '^')
				exponent = atoi(&nd[i + 2]);
			else
				exponent = 1;
		}
		else
			digit[j++] = nd[i];
	}

	num = atoi(digit);

#if __DEBUG__
	printf("num = %d\n", num);
#endif

	if(exponent == 1)
	{
		char sign;
		coef = 0.5;

		if(fabs(coef * num) == 1.0)
			;
		else
			// expression floating sprintf, and atof
			;

		if(coef * num > 0)
			;
		else
			sign = '-';

		lr[k++] = sign;
		lr[k++] = var;
		strncpy(&lr[k], "^2 + C", 6);
		printf("left = %s\n", lr);
	}
	else
		/* TODO */
		;

	return;

right:
	strncpy(&lr[k], "ln ", 3);
	lr[3] = nd[0];
	printf("right = %s\n", lr);

	if(div_flag)
	{
	}
	else
		// TODO
		;
}

void solve_ode(char *expr)
{
	int idx;
	bool div_flag;
	char depend_ch;
	char non_depend[32] = {0};

	char left[32] = {0};
	char right[32] = {0};

	idx = find_prime_idx(expr, &depend_ch);
	div_flag = seperate_non_depend(expr, idx, depend_ch, non_depend);

#if __DEBUG__
	printf("nd = %s\n", non_depend);
#endif

	integral(left, non_depend, LEFT, div_flag);
	integral(right, &depend_ch, RIGHT, div_flag);
}

int main(void)
{
	float sample_x[10001] = {0};
	float orig_y[10001] = {0};
	float y_prime[10000] = {0};
	float restore_data[10001] = {0};

	init_sample_x(sample_x);
	init_sample_data(orig_y, sample_x);

	calc_derivative(y_prime, orig_y);
	//print_arr(y_prime, 10000);

	printf("Solve y' = -2xy\n");
	solve_ode("y' = -2xy");

	return 0;
}
