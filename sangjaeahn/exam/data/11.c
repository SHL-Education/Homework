#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#define EMPTY 0



struct node{
	int data;
	struct node *link;
};
typedef struct node Stack;

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

avl *get_avl_node(void)
{
	avl *tmp;
	tmp = (avl *)malloc(sizeof(avl));
	tmp->lev = 1;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

Stack *get_node()
{
	Stack *tmp;
	tmp=(Stack *)malloc(sizeof(Stack));
	tmp->link=EMPTY;
	return tmp;
}
void push(Stack **top, int data)
{
	Stack *tmp;
	tmp = *top;
	*top = get_node();
	(*top)->data = data;
	(*top)->link = tmp;
}

int pop(Stack **top)
{
	Stack *tmp;
	int num;
	tmp = *top;
	
	if(*top == EMPTY)
	{
		printf("Stack is empty!!!\n");
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
		arr[i] = (rand() % 100) +1;

		if(is_dup(arr, i))
		{
			printf("%d dup! redo rand()\n", arr[i]);
			goto redo;
		}
	}
}
	
void print_stack(Stack **top)
{
	Stack *tmp = *top;

	while(tmp != 0)	
	{
		printf("%d\n", tmp->data);
		tmp = tmp->link;
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

int kinds_of_rot(avl *root, int data)
{
	printf("data = %d\n", data);

	if(rotation_check(root) > 1)
	{
		if(root->right->data > data)
			return RL;

		return RR;
	}
	else if(rotation_check(root) < -1)
	{
		if(root->left->data < data)
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

void print_tree(avl **root)
{
	if(*root)
	{
		printf("data = %d, lev = %d, ", (*root)->data, (*root)->lev);

		if((*root)->left)
			printf("left = %d, ", (*root)->left->data);
		else
			printf("left = NULL, ");

		if((*root)->right)
			printf("right = %d\n", (*root)->right->data);
		else
			printf("right = NULL\n");

		print_tree(&(*root)->left);
		print_tree(&(*root)->right);
	}
}

void insert_odd(Stack **top,avl **root, int size)
{
	int i=0, data[20];
	
	for(i=0;i<size;i++)
	{
		data[i] = pop(top);
	
		if(data[i]%2)
		{
			avl_ins(root,data[i]);
		}
	}
}

int main(void)
{
	Stack *top = EMPTY;
	
	int arr[20] = {0,};
	int size = sizeof(arr)/sizeof(int);
	int i, data[20] = {0,};
	avl *root = 0;

	srand(time(NULL));
	init_rand_arr(arr, size);
	
	for(i=0;i<size;i++)
	{
		push(&top, arr[i]);
	}
	
	print_stack(&top);
	printf("\n");
	
	insert_odd(&top,&root,size);
	
	print_tree(&root);	
	
	return 0;
}
