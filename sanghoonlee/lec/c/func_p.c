#include <stdio.h>

typedef struct test_class
{
	int in1;
	int in2;
	double dn1;
	double dn2;

	int (*int_op)(int, int);
	double (*double_op)(double, double);
} tc;

int iadd(int n1, int n2)
{
	return n1 + n2;
}

int imul(int n1, int n2)
{
	return n1 * n2;
}

double dadd(double n1, double n2)
{
	return n1 + n2;
}

int main(void)
{
	int res;
	double dres;
	tc tc_inst = {3, 7, 2.2, 7.7, NULL, NULL};

	tc_inst.int_op = iadd;
	res = tc_inst.int_op(tc_inst.in1, tc_inst.in2);
	printf("res = %d\n", res);

	tc_inst.int_op = imul;
	res = tc_inst.int_op(tc_inst.in1, tc_inst.in2);
	printf("res = %d\n", res);

	tc_inst.double_op = dadd;
	dres = tc_inst.double_op(tc_inst.dn1, tc_inst.dn2);
	printf("dres = %lf\n", dres);

	return 0;
}
