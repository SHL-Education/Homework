#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __tree
{
	char *data;
	struct __tree *left;
	struct __tree *right;
} tree;

tree *get_node(void)
{
	tree *tmp;
	tmp = (tree *)malloc(sizeof(tree));
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

void tree_ins(tree **root, char *data)
{
	int size;

	if(*root == NULL)
	{
		*root = get_node();
		size = strlen(data);
		(*root)->data = (char *)malloc(size + 1);
		strncpy((*root)->data, data, size);
		return;
	}
	else if(strcmp((*root)->data, data) > 0)
		tree_ins(&(*root)->left, data);
	else if(strcmp((*root)->data, data) < 0)
		tree_ins(&(*root)->right, data);
}

void print_tree(tree *root)
{
	if(root)
	{
		printf("data = %s, ", root->data);

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

int main(void)
{
	int i;

	tree *root = NULL;
	char *data[13] = {"Let's go", "Hello", "Hi", "Gom Bang Wa", "Go", "Perl", "Python", "C", "Verilog", "VHDL", "C++", "Fortran", "Assembly Language"};

	for(i = 0; i < 13; i++)
		tree_ins(&root, data[i]);

	print_tree(root);

	return 0;
}
