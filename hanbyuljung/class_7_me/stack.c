#include<stdio.h>
#include<malloc.h>

#define EMPTY 0

struct node{

	int data;
	struct node *link;

};

typedef struct node Stack;

Stack *get_node()
{
	Stack *tmp;
	tmp =(Stack *)malloc(sizeof(Stack));
	tmp -> link = EMPTY;
	return tmp;
	
}

void push(Stack ** top, int data)
{
	Stack *tmp;
	tmp = *top;
	*top = get_node();
	(*top)->data = data;
	(*top)->link = tmp;
}

int pop(Stack ** top)
{

		Stack *tmp;
		int num;
		tmp = *top;
		if(*top == EMPTY)
		{
				printf("Stack is empty!!!\n");
				return 0;
		}
		num = tmp ->data;
		*top=(*top)->link;
		free(tmp);
		return num;
}

int main(void)
{

		Stack *top = EMPTY;
		push(&top, 10);
		push(&top, 20);
		push( &top, 30);
		printf("%d\n", pop(&top));
		printf("%d\n", pop(&top));
		printf("%d\n", pop(&top));
		printf("%d\n", pop(&top));
		return 0;
}
