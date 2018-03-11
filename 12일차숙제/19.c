/* 문제 : stack을 c언어로 구현해보시오*/

#include <stdio.h>
#include <stdlib.h>

typedef struct __stack{
	struct __stack *link;
	int data;
}stack;

stack* get_node(void)
{
	stack *tmp;
	tmp = (stack *)malloc(sizeof(stack));
	tmp->link = 0;
	return tmp;
}

void push(stack **top, int data)
{
	if(*top == 0)
	{
		*top = get_node();
		(*top)->data = data;
		return;
	}
	else
	{
		push(&(*top)->link,data);
	}
}

int pop(stack **top)
{
	int data;

	if((*top)->link == 0)
	{
		data = (*top)->data;		
		free(*top);	
	}
	else
	{
		data = pop(&(*top)->link);
	}
	
	return data;
}

int main(void)
{
	stack *top = NULL;
	push(&top, 1);
	push(&top, 2);
	printf("data = %d\n", pop(&top));

	return 0;
}

/* 결과값
data = 2
*/
