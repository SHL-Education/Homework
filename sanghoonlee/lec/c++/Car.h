#ifndef __CAR_H__
#define __CAR_H__

#include <string.h>

class Car{
private:
	float speed;
	char color[10];
	float fuel;
public:
	Car(float s, char *c, float f)
	{
		speed = s;
		strncpy(color, c, strlen(c) + 1);
		fuel = f;
	}

	void input_data(void);
	void print_car_info(void);
};

#endif
