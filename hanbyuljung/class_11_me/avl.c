#include <stdio.h>
#include <malloc.h>
#include <stdlib.h.>
#define EMPTY 0

typedef struct __tree
{
	int data;
	int level;
	struct __tree *link_left;
	struct __tree *link_right;
	
}tree;

tree *get_node()
{
	tree *tmp;
	tmp = (tree*)malloc(sizeof(tree));
	tmp -> link_left = EMPTY;
	tmp -> link_right = EMPTY;
	tmp -> level = 1;
	return tmp;
}

tree *chg_node(tree *head)
{
	tree *tmp = head;
	if(!(head->link_left)){
			free(tmp);
			return head->link_right;
	}
	else if(!(head->link_right)){
			free(tmp);
			return head->link_left;
	}
}
tree *find_max(tree *head , int *data)
{
	tree *tmp = head;
	if(head->link_right)
			head->link_right = find_max(head, data);
	else
	{
			*data = head->data;
			head = chg_node(head);
	}
	return head;
}
void avl_ins(tree **root, int data)
{
	if(!(*root))
	{
		(*root) =get_avl_node();
		(*root) -> data = data;
		return;
	}
	if((*root)->data >data)
			avl_ins(&(*root)->link_left,data);
	else if((*root)->data <data)
			avl_ins(&(*root)->link_right, data);

	//update_level(root);
	(*root) -> lev =update_level(*root);

	if(abs(rotation_check(*root)) > 1)
	{
			printf("Rotation!\n");
			*root = rotation(*root, kinds_of_rot(*root, data));
			// rotation(*root, kinds_of_rot(*root, data));
	}
}
void binary(tree **head, int data, int level)
{

	tree *tmp = *head
	if(*head  == NULL){
		*head = get_node();
		(*head) ->data = data;
	    tmp=(*head) ->level; 		

		return ;
	}
	else if((*head)->data > data)
			binary(&(*head)->link_left, data, level);
	else if((*head)->data < data)
			binary(&(*head)->link_right, data, level);
	
}


tree *debinary(tree *head, int data)
{
	int num;
	tree *tmp;
	printf("\n");

	if(head == NULL)
	{
			printf("값이 없습니다.\n");
			return NULL;
	}
	else if(head ->data > data)
		head->link_left = debinary(head->link_left,data);
	else if(head ->data< data)
		head->link_right = debinary(head->link_right,data);
	else if(head ->link_left && head ->link_right)
	{
		head->link_left = find_max(head->link_left,&num);
		head->data = num;
	}
	else
			head = chg_node(head);
	return head;
}


void print(tree *head)
{
	tree *tmp = head;
	if(head){

		printf("data = %d\n",head->data);
		print(head->link_left);
		print(head->link_right);

	}
}
int main(void)
{
	tree *head =EMPTY;
	int a[]={50,45,73,32,48,46,16,37,120,47,130,127,124};
	int i=0; 
	int len=sizeof(a)/sizeof(int); 
	for(i=0;i<len;i++)
			binary(&head,a[i]);
	print(head);
	debinary(head,73);
	print(head);




	return 0;
}
