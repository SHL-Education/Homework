#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct __tree	// 트리를 위한 구조체
{
	int data;
	struct __tree *left;
	struct __tree *right;
} tree;

typedef struct __stack // 스택을 위한 구조체
{
	void *data;
	struct __stack *link;
} stack;

stack *get_stack_node(void)	// 스택의 노드를 생성함.
{
	stack *tmp;
	tmp = (stack *)malloc(sizeof(stack));
	tmp->link = NULL;
	return tmp;
}

tree *get_tree_node(void)	// 트리의 노드를 생성함.
{
	tree *tmp;
	tmp = (tree *)malloc(sizeof(tree));
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

void *pop(stack **top)	// 트리의 출력을 위한 스택의 pop 함수 구현.
{
	stack *tmp = *top;
	void *data = NULL;

	if(*top == NULL)
	{
		printf("stack is empty!\n");
		return NULL;
	}

	data = (*top)->data;
	*top = (*top)->link;
	free(tmp);

	return data;
}

void push(stack **top, void *data)	// 트리의 출력을 위한 스택의 push함수 구현
{
	if(data == NULL)
		return;

	stack *tmp = *top;
	*top = get_stack_node();
	(*top)->data = malloc(sizeof(void *));
	(*top)->data = data;
	(*top)->link = tmp;
}

void non_recur_tree_ins(tree **root, int data)
{
	tree **tmp = root;

	while(*tmp)
	{
		if((*tmp)->data > data)	    // 삽입하려는 data가 노드의 data보다 작으면 왼쪽으로 이동.
			tmp = &(*tmp)->left;
		else if((*tmp)->data < data)	// 삽입하려는 data가 노드의 data보다 크면 오른쪽으로 이동.
			tmp = &(*tmp)->right;
	}

	*tmp = get_tree_node();	// 트리의 최하위 노드까지 왔으므로 노드를 생성하고 data를 저장함.
	(*tmp)->data = data;
}

bool stack_is_not_empty(stack *top)
{
	if(top != NULL)
		return true;
	else
		return false;
}

void print_tree(tree **root)
{
	tree **tmp = root;
	stack *top = NULL;

	push(&top, *tmp);

	while(stack_is_not_empty(top))
	{
		tree *t = (tree *)pop(&top);	// 출력을 할때에는 스택에서 pop을 해서 출력함.
		tmp = &t;

		printf("data = %d, ", (*tmp)->data);

		if((*tmp)->left)
			printf("left = %d, ", (*tmp)->left->data);
		else
			printf("left = NULL, ");

		if((*tmp)->right)
			printf("right = %d\n", (*tmp)->right->data);
		else
			printf("right = NULL\n");

		push(&top, (*tmp)->right);	// 노드를 이동시킬 때마다 스택에 push함.
		push(&top, (*tmp)->left);
	}
}

tree *chg_node(tree *root)
{
	tree *tmp = root;

	if(!root->right)
		root = root->left;
	else if(!root->left)
		root = root->right;

	free(tmp);

	return root;
}

void find_max(tree **root, int *data)
{
	tree **tmp = root;

	while(*tmp)
	{
		if((*tmp)->right)
			tmp = &(*tmp)->right;	// 오른쪽 자식 노드의 주솟값을 저장함.
		else
		{
			*data = (*tmp)->data;
			*tmp = chg_node(*tmp);
			break;
		}
	}
}

void non_recur_delete_tree(tree **root, int data)
{
	tree **tmp = root;
	int num;

	while(*tmp)
	{
		if((*tmp)->data > data)
			tmp = &(*tmp)->left;	/* 재귀함수가 아니기 때문에 
						   root를 가리키는 포인터의 변경을 막기위해
						   tmp를 이중 포인터로 선언을 하였고 
						   왼쪽 또는 오른쪽으로 이동할 때마다 노드의 주소값을 저장하는 식으로
						   이동함.*/
		else if((*tmp)->data < data)
			tmp = &(*tmp)->right;
		else if((*tmp)->left && (*tmp)->right)
		{
			find_max(&(*tmp)->left, &num);	// 왼쪽 서브트리에서 최댓값을 찾음.
			(*tmp)->data = num;		// 왼쪽 서브트리에서 찾은 최댓값 data를 지우려는 노드의 data에 저장함.
			return;
		}
		else	// 왼쪽,오른쪽 자식이 모두 존재하는 것이 아니라면 그냥 자식 노드를 부모노드로 올림.
		{
			(*tmp) = chg_node(*tmp);
			return;
		}
	}

	printf("Not Found\n");
}

int main(void)
{
	int i;
	int data[14] = {50, 45, 73, 32, 48, 46, 16,
                      37, 120, 47, 130, 127, 124};

	tree *root = NULL;

	for(i = 0; data[i]; i++)
		non_recur_tree_ins(&root, data[i]);

	print_tree(&root);

	non_recur_delete_tree(&root, 50);
	printf("After Delete\n");

	print_tree(&root);
	
	return 0;
}

/*
재귀함수를 사용하지 않고 트리를 구현함.
*/
