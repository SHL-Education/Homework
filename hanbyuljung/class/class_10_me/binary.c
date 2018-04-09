#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>


#define EMPTY 0

typedef struct __tree
{
	int data;
	struct __tree *link_right;
	struct __tree *link_left;

}tree;

tree *get_node()
{
	tree *tmp;
	tmp = (tree*)malloc(sizeof(tree));
	(tmp)->link_right = EMPTY;
	(tmp)->link_left = EMPTY;
	return tmp;
}

void binary(tree **root, int data)
{
	tree *tmp = *root;
	if(tmp == NULL){
			*root = get_node();
			(*root)->data = data;
			return ;
	}
	if((*root)->data > data)
	{
			 binary(&(*root)->link_left, data);
	}
	else if((*root)->data < data)
	{
			 binary(&(*root)->link_right, data);
	}

}
void print(tree *root)
{
	tree *tmp =root;
	if(root)
	{
		printf("data = %d ,", tmp->data);
		if(root->link_left){
			printf("left = %d, " ,root->link_left->data);
		}
		else
			printf("left = NUll, ");
		if(root->link_right){
				printf("right = %d\n", root->link_right->data);
		}
		else
				printf("right = NULL\n");


		print(root->link_left);
		print(root->link_right);
	}

}


int main(void)
{
	tree *root=EMPTY;
	int a[]={50, 45, 73, 32, 48, 46, 16, 37, 120, 47, 130 ,127, 124}; 
	int i, num=0;
	int len = sizeof(a)/sizeof(int);

	printf("len = %d \n",len);

	for(i =0;i<len;i++)
	{
		binary(&root,a[i]);
	}
	print(root);


	return 0;
}
