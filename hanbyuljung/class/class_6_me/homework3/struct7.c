#include<stdio.h>


typedef struct add_class
{
	int in1;
	int in2;
	double dn1;
	double dn2;

	int (*int_op)(int, int);
	double (*double_op)(double, double);

}ac;

int iadd(int n1, int n2)
{
	return n1 +n2;


}


int imul(int n1, int n2)
{
	return n1 *n2;
}

double dadd(double n1, double n2)
{
		return n1+n2;
}
int main(void)
{
	int res;
	double dres;
	
	ac ac_inst = {3,7,2.2,7.7,NULL,NULL};

	ac_inst.int_op = iadd;
	res = ac_inst.int_op(ac_inst.in1, ac_inst.in2);
	printf("res = %d \n",res);


	ac_inst.int_op = imul;
	res = ac_inst.int_op(ac_inst.in1, ac_inst.in2);
	printf("res = %d \n",res);


	ac_inst.double_op = dadd;
	dres = ac_inst.double_op(ac_inst.dn1, ac_inst.dn2);
	printf("dres = %lf \n",dres);

	return 0;

}
