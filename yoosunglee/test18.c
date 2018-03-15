#include<stdio.h>

struct pos{
	
	double x_pos;
	double y_pos;
};

int main(void)
{
	double num;
	struct pos position;

	num = 1.2;
	position.x_pos = 7.7;
	position.y_pos = 2.2;

	printf("sizeof(position)=%d\n",sizeof(position));
	printf("%lf\n",position.x_pos);
	printf("%lf\n",position.y_pos);
	return 0;
}
