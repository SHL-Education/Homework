#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0	

typedef struct _stack{

	int data;
	struct _stack *link;

}stack;

stack *get_node()
{
	stack *tmp;
	tmp = (stack *)malloc(sizeof(stack));
	tmp->link = EMPTY;

	return tmp;
}

void push(stack **top, int data)
{
	stack *tmp;

	tmp = *top;

	*top = get_node();		//push 될때마다 top 또한 계속 생성
					//a->b
	(*top)->data = data;

	(*top)->link = tmp;

}

int pop(stack **top)
{
	int data;

	stack *tmp;

	if((*top)->link == EMPTY)
	{
		printf("stack is empty\n");
	}
	
	tmp = (*top);

	data = tmp->data;

	*top = tmp->link;

	free(tmp);	

	return data;
}


int main(void)
{

	stack *top;


	push(&top,10);
	push(&top,20);
	push(&top,30);
	
	printf("First Pop: %d\n", pop(&top));
	printf("second Pop: %d\n", pop(&top));
	//printf("third Pop: %d\n", pop(&top));


	return 0;
}
