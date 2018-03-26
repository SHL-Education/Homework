#include <stdio.h>
#include <math.h>

typedef struct __coord
{
	float x;
	float y;
} coord;

void init_coord(coord *A, int x, int y)
{
	A->x = x;
	A->y = y;
}

float calc_vec_area(coord *A, coord *B)
{
	return 0.5 * fabs(A->x * B->y - B->x * A->y);
}

int main(void)
{
	coord A;
	coord B;
	float area;

	init_coord(&A, 3, 6);
	init_coord(&B, 4, 4);

	area = calc_vec_area(&A, &B);
	printf("area = %f\n", area);

	return 0;
}

/*

*/
