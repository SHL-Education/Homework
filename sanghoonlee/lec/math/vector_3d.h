#ifndef __VECTOR_3D_H__
#define __VECTOR_3D_H__

typedef struct vector3d
{
	float x;
	float y;
	float z;

	void (* add)(struct vector3d, struct vector3d, struct vector3d *);
	void (* sub)(struct vector3d, struct vector3d, struct vector3d *);
	void (* scale)(float, struct vector3d);
	void (* dot)(struct vector3d, struct vector3d);
	void (* cross)(struct vector3d, struct vector3d);
} vec3;

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

#endif
