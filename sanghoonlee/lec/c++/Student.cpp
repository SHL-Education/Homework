#include <iostream>
#include "Student.h"

using namespace std;

void Student::input_score(void)
{
	cout << "Input math, physics, computer score" << endl;
	cin >> math;
	cin >> physics;
	cin >> computer;
}

void Student::calc_total(void)
{
	total = math + physics + computer;
}

void Student::average(void)
{
	ave = (float)(total / 3.0);
}

void Student::print_average(void)
{
	cout << "Average = " << ave << endl;
}
