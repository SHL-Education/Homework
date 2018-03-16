#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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

typedef struct __stack
{
	int data;
	struct __stack *link;
} stack;

stack *get_stack_node(void)
{
	stack *tmp;
	tmp = (stack *)malloc(sizeof(stack));
	tmp->link = NULL;
	return tmp;
}

void push(stack **top, int data)
{
	stack *tmp;
	tmp = *top;
	*top = get_stack_node();
	(*top)->data = data;
	(*top)->link = tmp;
}

int pop(stack **top)
{
	stack *tmp;
	int num;
	tmp = *top;

	if(*top == NULL)
	{
		printf("Stack is empty\n");
		return 0;
	}

	num = tmp->data;
	*top = (*top)->link;
	free(tmp);

	return num;
}

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

int find_pop(stack **top, int data)
{
	stack **tmp;
	stack **backup;
	int num;
	tmp = top;

	while(*tmp)
	{
		if((*tmp)->data != data)
		{
			backup = tmp;
			tmp = &(*tmp)->link;
		}
		else
		{
			num = (*tmp)->data;
			(*tmp) = (*tmp)->link;
			//*backup = (*tmp)->link;
			break;
		}
	}

	free(*tmp);

	return num;
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

		usleep(1000000);
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

	//update_level(root);
	(*root)->lev = update_level(*root);

	if(abs(rotation_check(*root)) > 1)
	{
		printf("Insert Rotation!\n");
		*root = rotation(*root, kinds_of_rot(*root));
		//rotation(*root, kinds_of_rot(*root, data));
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
		*root = rotation(*root, kinds_of_rot(*root));
		//rotation(*root, kinds_of_rot(*root, data));
	}
}


int main(void)
{
	int i;
	int p_data = 0;
	int data[11] = {0};
	stack *top = NULL;
	avl *root = NULL;
	int size = sizeof(data) / sizeof(int) - 1;

	srand(time(NULL));

	init_rand_arr(data, size);
	print_arr(data, size);

	for(i = 0; i < size; i++)
		push(&top, data[i]);

#if ITS_FOR_DEBUG
	printf("\nFind Pop!\n");
	printf("%d\n", find_pop(&top, data[0]));
#endif

#if 0
	for(i = 0; i < size; i++)
	{
		if(data[i] % 2)
		{
			p_data = find_pop(&top, data[i]);
			printf("data = %d\n", p_data);
			avl_ins(&root, p_data);
		}
	}

	print_tree(root);
#endif

#if 0
	avl_ins(&root, 41);
	avl_ins(&root, 29);
	avl_ins(&root, 83);
	avl_ins(&root, 51);
	avl_ins(&root, 59);

	print_tree(root);
#endif
	
#if 1
	avl_ins(&root, 13);
	avl_ins(&root, 41);
	avl_ins(&root, 47);
	avl_ins(&root, 29);
	avl_ins(&root, 17);
	avl_ins(&root, 3);

	print_tree(root);
#endif

	return 0;
}
