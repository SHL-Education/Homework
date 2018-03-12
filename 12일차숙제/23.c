#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RR 0
#define LL 1
#define RL 2
#define LR 3

typedef struct __tree{
	struct __tree *left;
	struct __tree *right;
	int data;
	int level;
}avl_tree;

avl_tree* get_node(void)
{
	avl_tree *tmp;
	tmp = (avl_tree *)malloc(sizeof(avl_tree));
	tmp->left = 0;	
	tmp->right = 0;
	tmp->level = 1;
	
	return tmp;
}

avl_tree * change_node(avl_tree *root)
{
	return root->left;
}

avl_tree * find_max(avl_tree *root, int *data)
{
	if(root->right)
	{
		root->right = find_max(root->right, data);
	}
	else if(!root->right)
	{
		*data = root->data;
		root = change_node(root);
	}
	
	return root;
}

void delete(avl_tree **root, int data)
{
	if(data < (*root)->data)
 	{
		delete(&(*root)->left, data);
	}	
	else if(data > (*root)->data)
	{
		delete(&(*root)->right, data);
	}
	else if((*root)->left && (*root)->right)
	{
		(*root)->left = find_max((*root)->left, &data);	
		(*root)->data = data;
	}
	else 
	{
		*root = change_node(*root);
	}
}

int rotation_check(avl_tree **root)
{
	int right = (*root)->right ? (*root)->right->level : 0;
	int left = (*root)->left ? (*root)->left->level : 0;
	
	return right - left;
}

int updata_level(avl_tree **root)
{
	int right = (*root)->right ? (*root)->right->level : 0;
	int left = (*root)->left ? (*root)->left->level : 0;
	
	if(right > left)
	{
		return right+1;
	}
	else
	{
		return left+1;
	}
}

int kinds_of_rotation(avl_tree *root, int data)
{
	if(rotation_check(&root) > 1)
	{
		if(data < root->right->data)
		{
			return RL;
		}
		else
		{
			return RR;
		}
	}
	else if(rotation_check(&root) < -1)
	{
		if(data > root->left->data)
		{
			return LR;
		}	
		else
		{
			return LL;
		}
	}	
}

avl_tree * RR_rotation(avl_tree * parent, avl_tree * child)
{
	parent->right = child->left;
	child->left = parent;	
	return child;
}

avl_tree * LL_rotation(avl_tree * parent, avl_tree * child)
{
	parent->left = child->right;
	child->right = parent;
	return child;
}

avl_tree * RL_rotation(avl_tree *parent, avl_tree * child)
{
	avl_tree * tmp;
	tmp = LL_rotation(child, child->left);
	tmp = RR_rotation(parent, tmp);
	return tmp;
}

avl_tree * LR_rotation(avl_tree *parent, avl_tree * child)
{
	avl_tree *tmp;
	tmp = RR_rotation(child, child->right);
	tmp = LL_rotation(parent, tmp);
	return tmp;
}	

avl_tree * rotation(avl_tree **root, int data)
{
	int ret = kinds_of_rotation(*root, data);
	
	switch(ret)
	{
		case RL:
			return RL_rotation(*root, (*root)->right);
		case RR:
			return RR_rotation(*root, (*root)->right);
		case LR:
			return LR_rotation(*root, (*root)->left);
		case LL:
			return LL_rotation(*root, (*root)->left);
	}
}

void insert(avl_tree **root, int data)
{
	if(*root == 0)
	{
		*root = get_node();
		(*root)->data = data;
	}
	else if(data < (*root)->data)
	{
		insert(&(*root)->left, data);
	}
	else if(data > (*root)->data)
	{
		insert(&(*root)->right, data);
	}
	
	(*root)->level = updata_level(root);
	
	if(abs(rotation_check(root)) > 2)
	{
		*root = rotation(root,data);
	}
}

void print_tree(avl_tree **root)
{	
	if(*root)	
	{
		printf("%d\n",(*root)->data);
		print_tree(&(*root)->left);
		print_tree(&(*root)->right);	
	}
}

int main(void)
{
	avl_tree *root = 0;
	
	insert(&root, 100);
	insert(&root, 90);
	insert(&root, 80);
	insert(&root, 95);
	insert(&root, 120);
	insert(&root, 85);
	insert(&root, 130);
	insert(&root, 125);
	insert(&root, 105);
	insert(&root, 86);
	insert(&root, 87);
	
	print_tree(&root);
	
	//delete(&root, 120);
	
	//printf("\n");
	//print_tree(&root);
	return 0;
}
