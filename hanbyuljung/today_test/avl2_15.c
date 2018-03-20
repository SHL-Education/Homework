#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

#define EMPTY 0

typedef struct __avl
{
	int data;
	int level;
	struct __avl *link_left;
	struct __avl *link_right;

}avl;

typedef enum __rot
{
	RR,
	RL,
	LL,
	LR
}rot;


avl *get_node()
{
	avl *tmp;
	tmp = (avl*)malloc(sizeof(avl));
	tmp->link_left = EMPTY;
	tmp->link_right = EMPTY;
	return tmp;
}

int update_level(avl *root)
{
		int left = root->link_left ? root ->link_left->level :0;
		int right = root->link_right ? root ->link_right->level :0;

		if(left>right)
				return left+1;
		return right +1;
}

int rotation_check(avl *root)
{
	int left = root->link_left ? root -> link_left->level : 0;
	int right = root->link_right ? root -> link_right -> level : 0;

	return right - left ;
}

avl *chg_node(avl *root)
{
		avl *tmp = root;

		if(!(root->link_left)){
			free(tmp);
			return root ->link_right;
		}
		else if(!(root->link_right)){
			free(tmp);
			return root ->link_left;
		}
}
avl *find_max(avl *root, int *data)
{
	if(root->link_right){
			root->link_right = find_max(root->link_right, data);
	}
	else{ 
			*data = root->data;
			root= chg_node(root);
	}
	return root;
}
int kinds_of_rot(avl *root, int data)
{
	printf("data = %c\n", data);

	//for RR and RL

	if(rotation_check(root) >1)
	{
		if(root->link_right->data >data)
				return RL;
		return RR;
	}
	else if(rotation_check(root) <-1)
	{
		if(root->link_left->data < data)
				return LR;
		return LL;
	}
}


avl *rotation(avl *root , int num )
{
		avl *tmp = root;
		//RR:1
		//RL:2
		//LL:3
		//LR:4
	switch (num){
			case RR:	
					tmp = root ->link_right->link_left;
					root->link_right->link_left= root;
					root->link_right= tmp ;
					break;
			case RL:
					tmp = root ->link_right ->link_left ->link_left;
					root ->link_right ->link_left ->link_right =root ->link_right;
					root ->link_right ->link_left ->link_left= root;
					root->link_right ->link_left = 0;
					root ->link_right =tmp;
					
					break;
			case LL:
					tmp = root ->link_left->link_right;
					root->link_left->link_right= root;
					root->link_left= tmp ;
					break;
			case LR:
					tmp = root ->link_left ->link_right ->link_right;
					root ->link_left ->link_right ->link_left =root ->link_left;
					root ->link_left ->link_right ->link_right= root;
					root->link_left ->link_right = 0;
					root ->link_left =tmp;
					break;
			default:

					break;
	}

	return root;
}


void print(avl *root)
{
		avl *tmp =root;
		if(root){
		}
		printf("data = %c ,", tmp->data);
		if(root->link_left){
				printf("left = %c, " ,root->link_left->data);
		}
		else
				printf("left = NUll, ");
		if(root->link_right){
				printf("right = %c\n", root->link_right->data);
		}
		else
				printf("right = NULL\n");
		print(root->link_left);
		print(root->link_right);
}

void avl_ins(avl **root, int data)
{
	if(!(*root))
	{
			*root = get_node();
			(*root)->data = EMPTY;
			return ;
	}

	if((*root)->data > data)
	{
			avl_ins(&(*root)->link_left , data);
	}
	else if((*root)->data <data)
	{
			avl_ins(&(*root)->link_right , data);
	}

	(*root)->level = update_level(*root);

	if(abs(rotation_check(*root)) >1)
	{
		printf("Rotation \n");
		*root = rotation(*root,kinds_of_rot(*root,data));
	}
}
avl *debinary(avl *root,int data)
{
	int num;
	avl *tmp;
	if(root == NULL)
	{
			printf("Not Found\n");
			return NULL;
	}
	else if(root->data >data)
			root->link_left = debinary(root->link_left,data);
	else if(root->data <data)
			root ->link_right = debinary(root->link_right, data);
	else if(root->link_left && root->link_right)
	{
			root->link_left =find_max(root->link_left, &num);
			root->data = num;
	}
	else
			root=chg_node(root);
	return root;
}




int main(void)
{
	avl *root=EMPTY;
//	int a[]={50,45,73,32,48,46,16,37,120,127,124};
	int i, num=0;
//	int len = sizeof(a)/sizeof(int);

	char arr[]="today";

	for(i=0;i<strlen(arr);i++)
		avl_ins(&root, arr[i]);

	print(root);		

	return 0;
}
