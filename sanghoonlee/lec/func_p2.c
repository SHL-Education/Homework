#include <stdio.h>

int (* aaa(void))[2]
{
	static int a[2][2] = {{10, 20}, {30, 40}};
	printf("aaa called\n");
	return a;
}

int (*(* bbb(void))(void))[2]
{
	printf("bbb called\n");
	return aaa;
}

int (*(* ccc(void))(void))[2]
{
	printf("ccc called\n");
	return aaa;
}

int (*(* ddd(void))(void))[2]
{
	printf("ddd called\n");
	return aaa;
}

int (*(* eee(void))(void))[2]
{
	printf("eee called\n");
	return aaa;
}

int main(void)
{
	int (*ret)[2];
	int (*(*(*p[][2])(void))(void))[2] = {{bbb, ccc}, {ddd, eee}};
	int (*(*(*(*p1)[2])(void))(void))[2] = p;
	ret = ((*(*(*(*p1)[3])))()());
	printf("*ret[0] = %d\n", *ret[0]);
	printf("ret[0][0] = %d\n", ret[0][0]);
	printf("*ret[1] = %d\n", *ret[1]);
	printf("ret[1][1] = %d\n", ret[1][1]);
	return 0;
}
