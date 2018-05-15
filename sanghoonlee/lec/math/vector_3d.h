#ifndef __VECTOR_3D_H__
#define __VECTOR_3D_H__

#include <stdio.h>
#include <math.h>

typedef struct vector3d vec3;

struct vector3d
{
	float x;
	float y;
	float z;

	void (* add)(vec3, vec3, vec3 *);
	void (* sub)(vec3, vec3, vec3 *);
	void (* scale)(float, vec3, vec3 *);
	float (* dot)(vec3, vec3);
	void (* cross)(vec3, vec3, vec3 *);
	void (* print)(vec3);

	void (* gramschmidt)(vec3 *, vec3 *, vec3);
};

void vec3_add(vec3 a, vec3 b, vec3 *r)
{
	r->x = a.x + b.x;
	r->y = a.y + b.y;
	r->z = a.z + b.z;
}

void vec3_sub(vec3 a, vec3 b, vec3 *r)
{
	r->x = a.x - b.x;
	r->y = a.y - b.y;
	r->z = a.z - b.z;
}

void vec3_scale(float factor, vec3 a, vec3 *r)
{
	r->x = a.x * factor;
	r->y = a.y * factor;
	r->z = a.z * factor;
}

float vec3_dot(vec3 a, vec3 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

void vec3_cross(vec3 a, vec3 b, vec3 *r)
{
	r->x = a.y * b.z - a.z * b.y;
	r->y = a.z * b.x - a.x * b.z;
	r->z = a.x * b.y - a.y * b.x;
}

void print_vec3(vec3 r)
{
	printf("x = %f, y = %f, z = %f\n", r.x, r.y, r.z);
}

float magnitude(vec3 v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

void gramschmidt_normalization(vec3 *arr, vec3 *res, vec3 r)
{
	float mag = magnitude(arr[0]);
	r.scale(1.0 / mag, arr[0], &res[0]);
	r.print(res[0]);
}

#endif
