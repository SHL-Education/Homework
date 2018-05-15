#include "vector_3d.h"
#include <stdio.h>

void print_vec3(vec3 R)
{
	printf("x = %f, y = %f, z = %f\n", R.x, R.y, R.z);
}

int main(void)
{
	vec3 A = {3, 2, 1};
	vec3 B = {1, 1, 1};
	vec3 R = {0, 0, 0, vec3_add, vec3_sub};

	R.add(A, B, &R);
	print_vec3(R);

	R.sub(A, B, &R);
	print_vec3(R);

	return 0;
}
