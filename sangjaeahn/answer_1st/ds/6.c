#include <math.h>
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
	int data;
	struct __avl_tree *left;
	struct __avl_tree *right;
} avl;

bool is_dup(int *arr, int cur_idx)	// arr배열의 원소에 중복된 데이터가 있는지 체크함.
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

int update_level(avl *root)	// 노드의 레벨값을 갱신함.
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

int kinds_of_rot(avl *root, int data)	// 회전연산의 종류를 결정함.
{
	printf("data = %d\n", data);

	if(rotation_check(root) > 1)
	{
		if(rotation_check(root->right) < 0)
			return RL;

		return RR;
	}
	else if(rotation_check(root) < -1)
	{
		if(rotation_check(root->left) > 0)
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

avl *rl_rot(avl *parent, avl *child, int data)	// ll회전을 먼저하고, rr회전을 수행함.
{
	child = ll_rot(child, child->left);
	return rr_rot(parent, child);
}

avl *lr_rot(avl *parent, avl *child, int data)	// rr회전을 먼저하고, ll회전을 수행함.
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
	if(!(*root))	// avltree의 최하위까지 왔다면 data를 삽입함.
	{
		(*root) = get_avl_node();
		(*root)->data = data;
		return;
	}

	if((*root)->data > data)
		avl_ins(&(*root)->left, data);
	else if((*root)->data < data)
		avl_ins(&(*root)->right, data);

	(*root)->lev = update_level(*root); // data를 삽입했으면 레벨을 갱신함.

	if(abs(rotation_check(*root)) > 1)	// 양쪽 레벨의 차가 2이상이면 회전을 함.
	{
		printf("Insert Rotation!\n");
		*root = rotation(*root, kinds_of_rot(*root, data), data);	// 회전의 종류를 결정하고 회전연산 수행함.
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

	(*root)->lev = update_level(*root);	// 노드를 삭제하고, 노드의 레벨을 갱신함.

	if(abs(rotation_check(*root)) > 1)	// 양쪽 레벨의 차이가 2이상이면 회전을 함. 
	{
		printf("Delete Rotation!\n");
		*root = rotation(*root, kinds_of_rot(*root, data), data);	// 회전의 종류를 결정하고 회전 연산을 수행함.
	}
}

int main(void)
{
	int i;
	avl *root = NULL;
	avl *test = NULL;
	int arr[16] = {0};
	int size = sizeof(arr) / sizeof(int) - 1;

	int data[] = {100, 50, 200, 25, 75, 70};

	srand(time(NULL));

	init_rand_arr(arr, size);	// arr 배열의 원소에 1~100의 임의의 값을 셋팅함.
	print_arr(arr, size);	// arr배열의 원소를 출력함.

	for(i = 0; i < size; i++)
		avl_ins(&root, arr[i]);	// avltree에 arr[]배열의 원소들을 삽입함.

	print_tree(root);	// avltree 출력

	printf("\nAfter Delete\n");
	avl_del(&root, arr[3]);	// avltree에 해당 data를 삭제함.
	avl_del(&root, arr[6]);
	avl_del(&root, arr[9]);
	
	print_tree(root);

	return 0;
}

/*
avl_tree 구현
*/
