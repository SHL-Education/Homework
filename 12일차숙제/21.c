/*문제:Binary Tree를 구현하시오.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct __tree{
	struct __tree *left;
	struct __tree *right;
	int data;
}tree;

tree* get_node(void)
{
	tree *tmp;
	tmp = (tree *)malloc(sizeof(tree));
	tmp->left = 0;	
	tmp->right = 0;
	
	return tmp;
}

tree * change_node(tree *root)
{
	return root->left;
}

tree * find_max(tree *root, int *data)
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

void delete(tree **root, int data)
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

void insert(tree **root, int data)
{
	if(*root == 0)
	{
		*root = get_node();
		(*root)->data = data;
		return ; 	
	}
	else if(data < (*root)->data)
	{
		insert(&(*root)->left, data);
	}
	else if(data > (*root)->data)
	{
		insert(&(*root)->right, data);
	}
}

void print_tree(tree **root)
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
	tree *root = 0;
	
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
	
	delete(&root, 90);
	
	printf("\n");
	print_tree(&root);
	return 0;
}

/* 결과값
100
90
80
85
86
87
95
120
105
130
125

100
87
80
85
86
95
120
105
130
125
*/
