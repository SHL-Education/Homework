#include "Car.h"
#include <iostream>

using namespace std;

void Car::input_data(void)
{
	cout << "Input your data(speed, color, fuel)" << endl;
	cin >> speed;
	cin >> color;
	cin >> fuel;
}

void Car::print_car_info(void)
{
	cout << "speed = " << speed;
	cout << " color = " << color;
	cout << " fuel = " << fuel << endl;
}
