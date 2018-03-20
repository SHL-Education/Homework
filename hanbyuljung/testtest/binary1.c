#include<stdio.h>
#include<malloc.h>

#define EMPTY 0

typedef struct __tree
{
	int data;
	struct __tree *link_right;
	struct __tree *link_left;
}

tree get_node()
{
	tree *tmp;
	tmp = (tree
}
