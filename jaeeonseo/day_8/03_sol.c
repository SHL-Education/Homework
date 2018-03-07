#include <stdio.h>
#include <stdlib.h>

typedef struct node{

	int data;
	struct node *left_link;
	struct node *right_link;
}Tree;

Tree* get_node()
{
	Tree *tmp;
	tmp = (Tree *)malloc(sizeof(Tree));
	tmp->left_link = NULL;
	tmp->right_link = NULL;

	return tmp;
}


void Tree_ins(Tree** root, int data)
{
	if(*root == NULL)
	{

		*root = get_node();
		(*root)->data = data;
		return;
	}
		
	if((*root)->data > data)
		Tree_ins(&(*root)->left_link, data);
	else
		Tree_ins(&(*root)->right_link, data);
}

int Tree_search(Tree *root, int data)
{
	if(root == NULL)
	{
		printf("데이터가 존재하지 않습니다.\n");

		return 0;
	}

	if(root->data > data)
		Tree_search(root->left_link, data);
	else if(root->data == data)
		return data;
	else
		Tree_search((root)->right_link, data);
}

void preorder(Tree *root)
{
	if(root)
	{
		printf("%d	", root->data);
		preorder(root->left_link);
		preorder(root->right_link);
	}
}

void inorder(Tree *root)
{
	if(root)
	{
		inorder(root->left_link);
		printf("%d	", root->data);
		inorder(root->right_link);
	}
}

void postorder(Tree *root)
{
	if(root)
	{
		postorder(root->left_link);
		postorder(root->right_link);
		printf("%d	", root->data);
	}
}



Tree* node_change(Tree *root)
{
	Tree *tmp;
	tmp = root;

	if(!root->right_link)
		root = root->left_link;
	else if(!root->left_link)
		root = root->right_link;
	
	free(tmp);

	return root;
}

Tree* min_node(Tree *root, int *data)
{
	if(root->left_link)
		root->left_link = min_node(root->left_link, data);
	else
	{
		*data = root->data;
		root = node_change(root);
	}
	
	return root;
}

Tree* delete_Tree(Tree *root, int data)
{
	int num;
	Tree *tmp;

	if(root == NULL)
	{
		printf("not found");
		return NULL;
	}
	else if(root->data > data)
		root->left_link = delete_Tree(root->left_link, data);
	else if(root->left_link && root->right_link)
	{
		root->right_link = min_node(root->right_link, &num);
		root->data = num;
	}
	else
	{
		root = node_change(root);
	}

	return root;
}

int main(void)
{
	int i;
	int test[20] = {50, 45, 73, 32, 48, 46, 16, 37, 120, 47, 130, 127, 124};
	int end = sizeof(test)/sizeof(int);
	int data; 
	
	Tree *root = NULL;

	for(i = 0; test[i]; i++)
		Tree_ins(&root, test[i]);

	printf("기본데이터: ");

	for(i = 0; test[i]; i++)
		printf("%d ", test[i]);
	printf("\npreorder 데이터: ");
	preorder(root);
	printf("\ninorder 데이터: ");
	inorder(root);
	printf("\npostorder 데이터: ");
	postorder(root);
	printf("\n");

	data = Tree_search(root, 73);
	printf("Search data 73, found: %d\n", data);

	printf("Delete data 32\n");
	delete_Tree(root, 32);

	printf("\npreorder 데이터: ");
	preorder(root);
	printf("\ninorder 데이터: ");
	inorder(root);
	printf("\npostorder 데이터: ");
	postorder(root);
	printf("\n");

	return 0;
}
	


