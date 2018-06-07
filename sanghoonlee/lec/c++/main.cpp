#include "Student.h"

int main(void)
{
	Student ds;
	ds.input_score();
	ds.calc_total();
	ds.average();
	ds.print_average();

	Student sj;
	sj.input_score();
	sj.calc_total();
	sj.average();
	sj.print_average();
	
	return 0;
}
