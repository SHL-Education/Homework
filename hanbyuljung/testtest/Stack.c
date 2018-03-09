#include<stdio.h>
#include<malloc.h>

#define EMPTY 0

typedef struct __stack
{
	int data;
	struct __stack *link;

}stack;


stack *get_node()
{
	stack *tmp;
	tmp = (stack *)malloc(sizeof(stack));
	tmp-> link = EMPTY;
	return tmp;
}

void push(stack **top, int data)
{
	stack *tmp = *top;
	*top = get_node();
	(*top)->data = data;
	(*top)->link = tmp;
	
}
int pop(stack **top)
{
	stack *tmp = *top;
	int num;
	if(*top == NULL)
	{
		printf("stack is empty !!!\n");
		return 0;
	}
	num = tmp ->data;
	free(tmp);
	*top = (*top)->link;
	return num;

}
int main(void)
{
	stack *top = EMPTY;

	push(&top, 10);
	push(&top, 20);
	push(&top, 30);
	printf("%d \n", pop(&top));
	printf("%d \n", pop(&top));
	printf("%d \n", pop(&top));
	printf("%d \n", pop(&top));



	return 0;
}
