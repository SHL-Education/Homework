#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0

typedef struct _stack{

	int data;
	struct _stack *link;
}stack;


void  push(stack **top, int data)
{
	stack *tmp;

	tmp = (stack *)malloc(sizeof(stack));

	tmp->data = data;

	(*top)->link = tmp;

}


int pop(stack **top)
{
	stack *tmp;
	int data;
	
	tmp = (*top)->link;

	data = tmp->data;

	(*top)->link = tmp->link;

	free(tmp);

	return data;
}

stack top_node;

int main(void)
{
	
        stack *top = &top_node;
        push(&top, 10);
        push(&top, 20);
        push(&top, 30);
        printf("%d\n", pop(&top));   //와 pop()비교
        printf("%d\n", pop(&top));
        printf("%d\n", pop(&top));
        printf("%d\n", pop(&top));

        return 0;
}

