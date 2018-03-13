#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

#define EMPTY 0

typedef struct __tree
{
	int data;
	struct __tree *link_left;
	struct __tree *link_right;
}tree;




tree *chg_node(tree *root)
{
	tree *tmp = root;

	if(!(root->link_left)){
		root = root ->link_right;
	}
	else if(!(root->link_right))
	{
		root = root ->link_left;
	}

	free(tmp);
	return root;
}

void find_max(tree **root, int *data)
{
	tree **tmp = root;
	while(*tmp)
	{
		if((*tmp)->link_right)
			tmp = &(*tmp)->link_right;
		else
		{
			*data = (*tmp)->data;
			*tmp = chg_node(*tmp);
			break;
		}
	}
}


tree *get_node()
{
	tree *tmp;
	tmp = (tree*)malloc(sizeof(tree));
	tmp->link_left = EMPTY;
	tmp->link_right = EMPTY;
	return tmp;
}

void push(tree **root, int data)
{
	tree *tmp;
	tmp = *root;
	*root = get_node();
	(*root) -> data = data;
	(*root) -> link_right = tmp;
	(*root) -> link_left = tmp;
}

int pop(tree **root)
{
	tree *tmp = *root;
	int num;
	if(tmp == NULL){
		printf("값이 없다.\n");
		return 0;
	}
	num = tmp ->data;
	if((*root)->link_left)
		*root = (*root)->link_left;
	else 
		*root = (*root)->link_right;
	free(tmp);
	return num;



}
void binary(tree **root, int data)
{
	tree *tmp = *root;
	if((*root) == NULL){
		*root = get_node();
		(*root)->data = data;
		return ;
	}
	else if( (*root)->data > data)
		binary(&((*root)->link_left), data);
	else if ( (*root)->data < data)
		binary(&((*root)->link_right), data);
}

void binary_1(tree **root, int data)
{
	tree *tmp = *root;
	//printf("시작\n");
	//printf("tmp = %d\n",*root);

	while(root)
	{
		if( (*root)->data >data)
			 tmp = tmp ->link_left;  
		else if( (*root)->data <data)
			tmp = tmp->link_right;
	}
	*root = get_node();
	(*root)->data = data;
}

void binary_2(tree **root,  int data)
{
	tree **tmp = root;
	while(*tmp)
	{
		if((*tmp)->data >data)
			tmp = &(*tmp)->link_left;
		else if((*tmp)->data<data)
			tmp = &(*tmp)->link_right;
	}

	*tmp = get_node();
	(*tmp)->data = data;
}



/*
tree *del_binary(tree *root, int data)
{
	tree *tmp = root;
	int num;
	if(root == NULL)
		printf("값이 없습니다.\n");
	else if(root -> data > data)
		root->link_left = del_binary(root->link_left,data);
	else if(root -> data < data)
		;
	else if( root->link_left && root->link_right)
	{
		root -> link_left = find_max(&(root->link_left), &num);
		root -> data = num;

	}
	else
		root = chg_node(root);
	return root;
}
*/

void del_binary2(tree **root, int data)
{
	tree **tmp = root;
	int num;
	while(*tmp)
	{
		if((*tmp)->data>data)
			tmp = &(*tmp)->link_left;
		else if((*tmp)->data<data)
			tmp = &(*tmp)->link_right;
		else if((*tmp)->link_left && (*tmp)->link_right)
		{
			find_max(&(*tmp)->link_left, &num);
			(*tmp)->data = num;
			return ;
		}
		else
		{
			(*tmp)= chg_node(*tmp);
			return ;
		}
	}
	printf("Not Found\n");
}


void print(tree *root)
{
	tree *tmp = root;
	if(root)
	{
		printf("data = %d\n", tmp ->data);
		print(root->link_left);
		print(root->link_right);
	}
}

void print2(tree **root)
{
	tree *tmp = *root;
	int num;
	while(tmp)
	{
		if((*root)->link_left){
			tmp =(tmp)->link_left;
		//	printf("data = %d\in ",tmp->data);
		}

		else if((*root)->link_right){
			tmp =(tmp)->link_right;
		//	printf("data = %d\n", tmp->data);
		}
		
		else if(!((*root)->link_right && (*root)->link_left)){
			printf("data = %d \n", (tmp) ->data);
			free(tmp);
		}
	}
}
void print3(tree **root)
{
	tree *tmp = *root;
	int num;
	while(tmp)
	{
		if((*root)->link_left)
			tmp = tmp ->link_left;
		else if((*root)->link_right)
			tmp = tmp ->link_right;
		else if(!((*root)->link_right && (*root)->link_left))
			printf("%d\n", pop(&(*root)));
	}
}


int main(void)
{

	tree *root = EMPTY;
	int i;
	int a[]= {50,45,73,32,48,46,16,37,120,47,130,127};
	int len = sizeof(a)/sizeof(int);
	for(i=0; i<len ; i++)
		binary_2( &root , a[i]);
	print(root);
	del_binary2(&root, 45);
	print2(&root);

	return 0; 

}
