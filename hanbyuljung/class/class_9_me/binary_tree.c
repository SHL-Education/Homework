#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>

#define EMPTY 0

typedef struct __tree
{
	int data;
//	int data2;
	struct __tree *link_right;
	struct __tree *link_left;

}tree;

tree *get_node()
{
	tree *tmp;
	tmp = (tree *)malloc(sizeof(tree));
	tmp -> link_right = EMPTY;
	tmp -> link_left = EMPTY;
	return tmp;
}



void binary(tree **root, int data)
{
	tree *tmp = *root;
	if( *root == NULL){
	 	 *root = get_node();
		 (*root) -> data =data;
		 return ;
	}

	else if((*root)->data > data){
	//	(*root)->link_left = tmp;	
		binary(&((*root)->link_left), data);
	}
	else if((*root)->data <data){
	//	(*root)->link_right = tmp;
		 binary(&((*root)->link_right), data);
	}
	else
		printf("값이 같습니다.\n");
	
		
}

void print(tree *top)
{
	if(top)
	{
		printf("data = %d, ", top -> data);

		if(top->link_left)
				printf("left = %d, " , top ->link_left->data);
		else
				printf("left = NULL, ");
		if (top ->link_right)
				printf("right =%d \n", top ->link_right->data);
		else
				printf("right = NULL\n");



		print(top->link_left);
		// 맨위에 print(tree *top) 속에 top에 뭘 던질 것이냐...
		print(top->link_right);
		// 맨위에 print(
	}

}

int main(void)
{
	int a[] = {50,45,73,32,48,46,16,37,120,47,130,127,124};
	int len = (sizeof(a)/sizeof(int));
	int i;
	srand((unsigned)time(NULL));

	tree *top = EMPTY;
	for(i=0;i<len;i++)
		binary( &top, a[i]);

	printf("%d\n",len);
	print(top);


//	a[rand()%(sizeof(a)/(int))]


	return 0;
}
