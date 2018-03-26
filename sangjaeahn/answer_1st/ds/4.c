#include <stdio.h>
#include <stdlib.h>

typedef struct __tree
{
	int data;
	struct __tree *left;
	struct __tree *right;
} tree;

tree *get_node(void)
{
	tree *tmp;
	tmp = (tree *)malloc(sizeof(tree));	// 새로운 노드를 만듬.
	tmp->left = NULL;	
	tmp->right = NULL;
	return tmp;
}

void tree_ins(tree **root, int data)
{
	if(*root == NULL)		// 현재 위치에 노드가 없다면 노드를 만들고 삽입하려는 data를 삽입함.
	{
		*root = get_node();	
		(*root)->data = data;
		return;
	}
	else if((*root)->data > data)	// 삽입하려는 data가 현재 노드의 data보다 크다면 오른쪽으로 이동.
		tree_ins(&(*root)->left, data);
	else if((*root)->data < data)	// 삽입하려는 data가 현재 노드의 data보다 작다면 왼쪽으로 이동.
		tree_ins(&(*root)->right, data);
}

void print_tree(tree *root)	
{
	if(root)
	{
		printf("data = %d, ", root->data);

		if(root->left)
			printf("left = %d, ", root->left->data);
		else
			printf("left = NULL, ");

		if(root->right)
			printf("right = %d\n", root->right->data);
		else
			printf("right = NULL\n");

		print_tree(root->left);	
		print_tree(root->right);
	}
}

tree *chg_node(tree *root)
{
	tree *tmp = root;

	if(!root->right)	// 오른쪽 자식이 없다면 왼쪽 자식을 올림.
		root = root->left;
	else if(!root->left)	// 왼쪽 자식이 없다면 오른쪽 자식을 올림.
		root = root->right;

	free(tmp);	// 자식을 올리고나면 부모 노드는 없앰.

	return root;
}

tree *find_max(tree *root, int *data)
{
	if(root->right)
		root->right = find_max(root->right, data);	// 오른쪽 노드의 끝으로 이동.
	else
	{
		*data = root->data;	// 오른쪽 끝의 노드의 data를 포인터를 통해 넘겨줌.
		root = chg_node(root);	// 오른쪽 끝의 노드자리를 자식노드로 대체함.
	}

	return root;
}

tree *delete_tree(tree *root, int data)
{
	int num;
	tree *tmp;
	if(root == NULL)
	{
		printf("Not Found\n");
		return NULL;
	}
	else if(root->data > data)
		root->left = delete_tree(root->left, data);	// 삭제하려는 data가 노드의 data보다 작으면 왼쪽으로 이동.
	else if(root->data < data)
		root->right = delete_tree(root->right, data);	// 삭제하려는 data가 노드의 data보다 크면 오른쪽으로 이동.
	else if(root->left && root->right)
	{
		root->left = find_max(root->left, &num);	// 삭제하려는 data를 찾으면 왼쪽에서 가장 큰 data를 올림.
		root->data = num;
	}
	else
		root = chg_node(root);	/* 삭제하려는 노드의 자식노드가 모두 존재하는 것이 아니라면
					   자식노드를 부모 노드의 자리로 옮김 */
	return root;
}

int main(void)
{
	int i;
	int data[14] = {50, 45, 73, 32, 48, 46, 16,
                      37, 120, 47, 130, 127, 124};

	tree *root = NULL;

	for(i = 0; data[i]; i++)
		tree_ins(&root, data[i]);	// data[]배열의 data로 트리를 구성함. 

	print_tree(root);	// 트리의 모든 노드의 data를 출력함.

	delete_tree(root, 50);	// 50의 data를 가진 노드를 삭제함.
	printf("After Delete\n");

	print_tree(root);	// 트리의 모든 노드의 data를 출력함.
	
	return 0;
}

/*
트리 구현.
삽입, 삭제, 출력
*/
