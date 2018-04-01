#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum __rot
{
	RR,
	RL,
	LL,
	LR
} rot;

typedef struct __avl_tree
{
	int lev;
	char *data;
	struct __avl_tree *left;
	struct __avl_tree *right;
} avl;

bool is_dup(int *arr, int cur_idx)
{
	int i, tmp = arr[cur_idx];

	for(i = 0; i < cur_idx; i++)
		if(tmp == arr[i])
			return true;

	return false;
}

void init_rand_arr(int *arr, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
redo:
		//arr[i] = rand() % 15 + 1;
		arr[i] = rand() % 100 + 1;

		if(is_dup(arr, i))
		{
			printf("%d dup! redo rand()\n", arr[i]);
			goto redo;
		}
	}
}

void print_arr(int *arr, int size)
{
	int i;

	for(i = 0; i < size; i++)
		printf("arr[%d] = %d\n", i, arr[i]);
}

avl *get_avl_node(void)
{
	avl *tmp;
	tmp = (avl *)malloc(sizeof(avl));
	tmp->lev = 1;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

void print_tree(avl *root)
{
	if(root)
	{
		printf("data = %s, lev = %d, ", root->data, root->lev);

		if(root->left)
			printf("left = %s, ", root->left->data);
		else
			printf("left = NULL, ");

		if(root->right)
			printf("right = %s\n", root->right->data);
		else
			printf("right = NULL\n");

		print_tree(root->left);
		print_tree(root->right);
	}
}

int update_level(avl *root)
{
	int left = root->left ? root->left->lev : 0;
	int right = root->right ? root->right->lev : 0;

	if(left > right)
		return left + 1;

	return right + 1;
}

int rotation_check(avl *root)
{
	int left = root->left ? root->left->lev : 0;
	int right = root->right ? root->right->lev : 0;

	return right - left;
}

int kinds_of_rot(avl *root)
{
	// for RR and RL
	if(rotation_check(root) > 1)
	{
		if(rotation_check(root->right) < 0)
			return RL;

		return RR;
	}
	// for LL and LR
	else if(rotation_check(root) < -1)
	{
		if(rotation_check(root->left) > 0)
			return LR;

		return LL;
	}
}

avl *rr_rot(avl *parent, avl *child)
{
	//parent->right = child->left ? child->left : child->right;
	parent->right = child->left;
	child->left = parent;
	parent->lev = update_level(parent);
	child->lev = update_level(child);
	return child;
}

avl *ll_rot(avl *parent, avl *child)
{
	//parent->left = child->right ? child->right : child->left;
	parent->left = child->right;
	child->right = parent;
	parent->lev = update_level(parent);
	child->lev = update_level(child);
	return child;
}

avl *rl_rot(avl *parent, avl *child)
{
	child = ll_rot(child, child->left);
	return rr_rot(parent, child);
}

avl *lr_rot(avl *parent, avl *child)
{
	child = rr_rot(child, child->right);
	return ll_rot(parent, child);
}

avl *rotation(avl *root, int ret)
{
	switch(ret)
	{
		case RL:
			printf("RL Rotation\n");
			return rl_rot(root, root->right);
		case RR:
			printf("RR Rotation\n");
			return rr_rot(root, root->right);
		case LR:
			printf("LR Rotation\n");
			return lr_rot(root, root->left);
		case LL:
			printf("LL Rotation\n");
			return ll_rot(root, root->left);
	}
}



void avl_ins(avl **root, char *data)
{
	int size;

	if(*root == NULL)
	{
		(*root) = get_avl_node();
		size = strlen(data);
		(*root)->data = (char *)malloc(size + 1);
		strncpy((*root)->data, data, size);
		return;
	}

	// strcmp 의 특성 활용
	if(strcmp((*root)->data, data) > 0)
	{
		printf("take left: %s\n", data);
		avl_ins(&(*root)->left, data);
	}
	else if(strcmp((*root)->data, data) < 0)
	{
		printf("take right: %s\n", data);
		avl_ins(&(*root)->right, data);
	}

	//update_level(root);
	(*root)->lev = update_level(*root);

	if(abs(rotation_check(*root)) > 1)
	{
		printf("Insert Rotation!\n");
		*root = rotation(*root, kinds_of_rot(*root));
		//rotation(*root, kinds_of_rot(*root, data));
	}
}

int main(void)
{
	int i;
	avl *root = NULL;
	char *data[13] = {"Let's go", "Hello", "Hi", "Gom Bang Wa", "Go", "Perl", "Python", "C", "Verilog", "VHDL", "C++", "Fortran", "Assembly Language"};

	for(i = 0; i < 13; i++)
		avl_ins(&root, data[i]);

	print_tree(root);

	return 0;
}
