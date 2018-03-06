#include <stdio.h>
#include <stdlib.h>


#define LEVEL_LIMIT 3

typedef struct __BiLink{

	int data;
	struct __BiLink *pLeft;
	struct __BiLink *pRight;
}BiLink;

BiLink *gRootNode;

void SetRootNode(BiLink *node)
{

	gRootNode = node;
}

BiLink *GetRootNode()
{
	return gRootNode;
}
	

void InsertRootData(BiLink **node, int rootData)
{


	if(*node == NULL)
	{
		*node = (BiLink *)malloc(sizeof(BiLink));
		(*node)->data = rootData;
		return;
	}

	gRootNode = *node;


	(*node)->data = rootData;

}

void InsertDataToBinaryTree(BiLink *node, int data)
{
	BiLink *tmp


	if(node != NULL)
	{

		tmp = (BiLink *)malloc(sizeof(BiLink));

		tmp->data = data;


		if(data <= node->data)
		{
			node->pLeft = tmp;

			InsertDataToBinaryTree(node->pLeft, data);
		}
		else
		{
			node->pRight = tmp;
		
			InsertDataToBinaryTree(node->pRight, data);
		}


	}
}

BiLink *SearchNode(BiLink *node, int data)
{

	if(node != NULL)
	{
		if(data == node->data)
		{

			return node;
		}
		else
		{

			if(data < node->data)
			{

				SearchNode(node->pLeft, data);
			}
			else
			{

				SearchNode(node->pRight, data);
			}
		}

	}
}


		
void DeleteNodeValue(int data)
{
	BiLink *rootNode;
	BiLink *delNode;
	BiLink *tmp;

	rootNode = GetRootNode();

	delNode = SearchNode(rootNode, data);

	if(delNode != NULL)
	{

		tmp = --(delNode);
		tmp = delNode->pRight;

		free(delNode);
	}
}

		
	

int main(void)
{
	return 0;
}	 
