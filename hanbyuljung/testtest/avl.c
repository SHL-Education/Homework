#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>

#define EMPTY 0
typedef enum __rot
{
	RR,
	RL,
	LL,
	LR		
}rot;

typedef struct __avl
{
	int lev;
	int data;
	struct __avl *link_left;
	struct __avl *link_right;
}avl

avl *get_node()
{
	avl *tmp 
	tmp = (avl*)malloc(sizeof(avl));
	tmp ->link = EMPTY;
	return tmp;
}

void print(avl *root)
{
	if(root)
	{


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
	parent -> left = child ->right;
	child-> right = parent;
	parent->lev = update_level(parent);
	child-> lev = update_level(child); 
	return child;
}


avl lr_rot(avl *parent , avl *child)
{
	child = rr_rot(child, child->right);
	return ll_rot(parent, child);
}


avl* rl_rot(avl *parent, avl *child)
{
	child = rr_rot(child, child->rihgt);
	return ll_rot(parent, child);
}


avl *rotation(avl *root ,int ret)
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
	avl *tmp = *root;
	if(!(*root)){
		*root = get_node();
		(*root)->data = data;
		return ;
	}
	if((*root)->data > data)
		avl_ins(&(*root)->link_left, data);
	else if((*root)->data < data)
		avl_ins(&(*root)->link_right, data);

	//update_level(root);
	(*root)->lev = update_level(*root);

	if(abs(rotation_check(*root)) > 1)
	{
		printf("rotation!\n");
		*root= rotation(*root, kinds_of_rot(*root,data));
	}

}



int main(void)
{
	avl *root = EMPTY;


	return 0;
}
