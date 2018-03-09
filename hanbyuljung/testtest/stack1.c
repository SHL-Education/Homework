#include<stdio.h>
#include<malloc.h>

#define EMPTY 0

typedef struct __stack
{
		int data;
		struct __stack *link;
}Stack;


Stack *get_node()
{
	Stack *tmp;
	tmp = (Stack*)malloc(sizeof(Stack));
	(tmp)->link = EMPTY;

	return tmp;
}

void push(Stack **top, int data)
{
	Stack *tmp;
	tmp = *top;
	top = get_node();
	(*top)->data = data;
	(*top)->link = tmp;
}

int pop(Stack **top)
{
	Stack *tmp= *top;
	int num =EMPTY;
	
	if( *top == NULL)
	{
		printf("stack is empty !!!\n");
		return 0;
	}
	*top = (*top) ->link;
	num = tmp -> data; 
	free(tmp);

	return num;
}


int main(void)
{
	Stack *tmp = top;
	top =EMPTY;

	push(&top , 10);
	push(&top , 20);
	push(&top , 30);
	push(&top , 40);
	printf("%d\n", pop(top))


}
