nclude <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
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
	char str[100];
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
		printf("data = %d, lev = %d, ", root->data, root->lev);

		if(root->left)
			printf("left = %d, ", root->left->data);
		else
			printf("left = NULL, ");

		if(root->right)
			printf("right = %d\n", root->right->data);
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

int kinds_of_rot(avl *root, char str[100])
{
	printf("data = %d\n", data);

	if(rotation_check(root) > 1)
	{
		if(root->right->str > str)
			return RL;

		return RR;
	}
	else if(rotation_check(root) < -1)
	{
		if(root->left->str < str)
			return LR;

		return LL;
	}
}

avl *rr_rot(avl *parent, avl *child)
{
	parent->right = child->left;
	child->left = parent;
	parent->lev = update_level(parent);
	child->lev = update_level(child);
	return child;
}

avl *ll_rot(avl *parent, avl *child)
{
	parent->left = child->right;
	child->right = parent;
	parent->lev = update_level(parent);
	child->lev = update_level(child);
	return child;
}

avl *rl_rot(avl *parent, avl *child, int data)
{
	child = ll_rot(child, child->left);
	return rr_rot(parent, child);
}

avl *lr_rot(avl *parent, avl *child, int data)
{
	child = rr_rot(child, child->right);
	return ll_rot(parent, child);
}

avl *rotation(avl *root, int ret, int data)
{
	switch(ret)
	{
		case RL:
			printf("RL Rotation\n");
			return rl_rot(root, root->right, data);
		case RR:
			printf("RR Rotation\n");
			return rr_rot(root, root->right);
		case LR:
			printf("LR Rotation\n");
			return lr_rot(root, root->left, data);
		case LL:
			printf("LL Rotation\n");
			return ll_rot(root, root->left);
	}
}



void avl_ins(avl **root, int data)
{
	if(!(*root))
	{
		(*root) = get_avl_node();
		(*root)->data = data;
		return;
	}

	if((*root)->data > data)
		avl_ins(&(*root)->left, data);
	else if((*root)->data < data)
		avl_ins(&(*root)->right, data);

	(*root)->lev = update_level(*root);

	if(abs(rotation_check(*root)) > 1)
	{
		printf("Insert Rotation!\n");
		*root = rotation(*root, kinds_of_rot(*root, data), data);
	}
}

avl *chg_node(avl *root)
{
	avl *tmp = root;

	if(!root->right)
		root = root->left;
	else if(!root->left)
		root = root->right;

	free(tmp);

	return root;
}

avl *find_max(avl *root, int *data)
{
	if(root->right)
		root->right = find_max(root->right, data);
	else
	{
		*data = root->data;
		root = chg_node(root);
	}

	return root;
}

void avl_del(avl **root, int data)
{
	if(*root == NULL)
	{
		printf("There are no data that you find %d\n", data);
		return;
	}
	else if((*root)->data > data)
		avl_del(&(*root)->left, data);
	else if((*root)->data < data)
		avl_del(&(*root)->right, data);
	else if((*root)->left && (*root)->right)
		(*root)->left = find_max((*root)->left, &(*root)->data);
	else
	{
		*root = chg_node(*root);
		return;
	}

	(*root)->lev = update_level(*root);

	if(abs(rotation_check(*root)) > 1)
	{
		printf("Delete Rotation!\n");
		*root = rotation(*root, kinds_of_rot(*root, data), data);
	}
}

int main(void)
{
	int i;
	avl *root = NULL;
	avl *test = NULL;
	int arr[16] = {0};
	int size = sizeof(arr) / sizeof(int) - 1;

	char str[100];

	srand(time(NULL));

	init_rand_arr(arr, size);
	print_arr(arr, size);

	printf("\nDebug AVL\n");

	for(i = 0; i < 6; i++)
		scanf("%s",str);
		avl_ins(&test, data[i]);

	print_tree(test);

	return 0;
}
