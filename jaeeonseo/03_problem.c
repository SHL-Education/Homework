#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1


typedef struct __BiLink{

	int data;
	struct __BiLink *pLeft;  //노드보다 작은 값
	struct __BiLink *pRight; //노드보다 큰 값

}BiLink;
	



BiLink *InsertDataToBinaryTree(BiLink **node, int data)
{
	BiLink *tmp = NULL;

	if(*node == NULL)
	{
		*node = (BiLink *)malloc(sizeof(BiLink));
		(*node)->data = data;
		(*node)->pLeft = NULL;
		(*node)->pRight = NULL;
		return NULL;
	}

	if(data <= (*node)->data)
	{
		InsertDataToBinaryTree(&(*node)->pLeft, data);
	}
	else if(data > (*node)->data)
	{
		InsertDataToBinaryTree(&(*node)->pRight, data);
	}

	return NULL;
}

BiLink *find_max(BiLink *root, int *data)
{

        while(root->pRight)
        {
                root = root->pRight;
        }

        *data = root->data;

        return root;
}

BiLink *chg_node(BiLink *root)
{
	int data;
	BiLink *tmp = root;
	BiLink *tmp1 = NULL;
	BiLink *tmp2 = NULL;

	if((root->pLeft != NULL)&&(root->pRight != NULL))
	{
		tmp1 = root->pLeft;
		tmp2 = find_max(root, &data);
		tmp2->pRight = tmp1;
		

	}
	else if((root->pLeft != NULL)||(root->pRight != NULL))
	{
		if(!root->pLeft)
			root = root->pRight;
		else if(!root->pRight)
			root = root->pLeft; 
	}

	free(tmp);

	return NULL;
}

void delete_tree(BiLink *root, int data)
{
        int num;
        BiLink *tmp;

	if(root != NULL)
	{		
	  	if(data < root->data)
	        {
			delete_tree(root->pLeft, data);	
       		}
       	        else if(data > root->data)
        	{
			delete_tree(root->pRight, data);
        	}
        	else if(root->data == data)
        	{
                	chg_node(root);
        	}

        
	}


}

/*		
int DeleteNodeValue(int data)
{
	BiLink *rootNode=NULL;
	BiLink *delNode=NULL;
	BiLink *tmp=NULL;
	BiLink *tmp1=NULL;
	BiLink *tmp2=NULL;
	
	rootNode = GetRootNode();

	delNode = SearchNode(&rootNode, data);
//	printf("delNode->data = %d\n", delNode->data);

	if(delNode)
	{
		tmp = delNode;
		//1. 현 노드 기준 왼(o), 오(o)
		if((delNode->pRight != NULL) && (delNode->pLeft != NULL))
		{
			tmp2 = delNode->pLeft;	//현재 delnode의 left

			tmp1 = delNode->pRight;	//현재 delnode의 right

			delNode = tmp1;		//delNode에 right주소 대입
			
			while(tmp1->pLeft)	//delNode->pRight->pLeft->pLeft....
			{
				tmp1 = tmp1->pLeft;
			}

			tmp1->pLeft = tmp2;	//delNode->pLeft....->pLeft = 초기 delnode->pLeft 
		}
		else if((delNode->pRight != NULL) || (delNode->pLeft == NULL))
		{	//2. 왼(x), 오(o)   //3. 왼(o), 오(x)
			
			if(!delNode->pLeft)
			{
				delNode = delNode->pRight;
			}
			else if(!delNode->pRight)
			{
				delNode = delNode->pLeft;
			}

		}
		
		free(tmp);
	}


	return 0;
}
*/

void print_tree(BiLink *root)
{
	if(root != NULL)
	{
		printf("data:%d ", root->data);
		print_tree(root->pLeft);
		print_tree(root->pRight);
	}
}
		

int main(void)
{
	int data, i;
	int arrayData[13] = {50, 45, 73, 32, 48, 46, 16, 37, 120, 47, 130, 127, 124};
	BiLink *root = NULL;
	BiLink *tmp = NULL;
	int retVal = 0;


	for(i=0; i < 13; i++)
	{
		InsertDataToBinaryTree(&root, arrayData[i]);
	}
	
	delete_tree(root, 73);
	
	print_tree(root);
	
	return 0;

}	 
