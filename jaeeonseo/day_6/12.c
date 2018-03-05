#include <stdio.h>


typedef struct add_class
{
	int in1;
	int in2;
	double dn1;
	double dn2;

	int (*int_op)(int, int);
	double (*double_op)(double, double);
}ac;


int Iadd(int n1, int n2)
{
	return n1+n2;
}

int Imul(int n1, int n2)
{
	return n1*n2;
}

double Dadd(double n1, double n2)
{
	return n1*n2;
}



int main(void)
{
	int res;
	double dres;
	ac tc_inst = {3, 7, 3.3, 7.7, NULL, NULL};
	
	tc_inst.int_op = Iadd;
	res = tc_inst.int_op(tc_inst.in1, tc_inst.in2);
	printf("res = %d\n", res);

	tc_inst.int_op = Imul;
	res = tc_inst.int_op(tc_inst.in1, tc_inst.in2);
	printf("res = %d\n", res);

	tc_inst.double_op = Dadd;
	dres = tc_inst.double_op(tc_inst.dn1, tc_inst.dn2);
	printf("dres = %lf\n", dres);

	return 0;

	
}
