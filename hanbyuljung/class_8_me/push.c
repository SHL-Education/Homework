#include<stdio.h>
#include<malloc.h>

#define EMPTY 0

struct node
{
	int data;
	struct node *link;

};

typedef struct node Stack;

Stack *get_nod()
{
	Stack *tmp;
	tmp = (Stack *)malloc(sizeof(Stack));
	tmp -> link = EMPTY;
	return tmp;
}

void push(Stack **top, int data)
{
	Stack *tmp;
	tmp = *top;
	*top = get_nod();
	(*top) -> data = data;
	(*top) -> link = tmp;
	
}

int pop(Stack **top)
{
	Stack *tmp;
	int num;
	tmp = *top;
	if(tmp == NULL){
			printf("값이 없다\n");
			return 0;
	}
	num = tmp -> data;
	*top = (*top)->link;
	free(tmp);
	return num;
}

int main(void)
{
	Stack *top;
	top = EMPTY;
	push(&top, 10);
	push(&top, 20);
	push(&top, 30);
	printf("%d\n", pop(&top));
	printf("%d\n", pop(&top));
	printf("%d\n", pop(&top));
	printf("%d\n", pop(&top));


	return 0;
}
