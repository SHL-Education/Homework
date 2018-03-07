typedef struct __tree{

	int data;
	struct __tree *pLeft; //data보다 큰 값
	struct __tree *pRight; //data보다 작은 값
}tree;




tree *delete_tree(tree *root, int data)
{
	int num;
	tree *tmp;

	if(root == NULL)
	{
		printf("Not Found\n");
		return 	NULL;
	}
	else if(root->data > data)
	{
		root->left = delete_tree(root->left, data);
	}
	else if(root->data < data)
	{
		root->pLeft = find_max(root->left, &num);
		root->data = num;
	}
	else
	{
		root = chg_node(root);
	}

	return root;
}

tree *find_max(tree *root, int *data)
{

	while(root->pLeft)
	{
		root = root->pLeft;
	}

	*data = root->data;

	return root;
}

tree *chg_node(tree* root)	//뭐하는 거지?
{				//root 메모리 삭제 후 root 포인터 옮김
	tree* tmp;

	tmp = root;

	if(!root->pLeft)
		root = root->pRight;
	else if(!root->pRight)
		root = root->pLeft;

	free(tmp);

	return root;
		
}
		
