#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct __stack
{
	int data;
	struct __stack *link;
} stack;

stack *get_stack_node(void)
{
	stack *tmp;
	tmp = (stack *)malloc(sizeof(stack));
	tmp->link = NULL;
	return tmp;
}

void push(stack **top, int data)
{
	stack *tmp;
	tmp = *top;
	*top = get_stack_node();
	(*top)->data = data;
	(*top)->link = tmp;
}

int pop(stack **top)
{
	stack *tmp;
	int num;
	tmp = *top;

	if(*top == NULL)
	{
		printf("Stack is empty\n");
		return 0;
	}

	num = tmp->data;
	*top = (*top)->link;
	free(tmp);

	return num;
}

bool is_dup(int *arr, int cur_idx)
{
	int i, tmp = arr[cur_idx];

	for(i = 0; i < cur_idx; i++)
		if(tmp == arr[i])
			return true;

	return false;
}

void init_rand_arr(int *arr, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
redo:
		arr[i] = rand() % 100 + 1;

		if(is_dup(arr, i))
		{
			printf("%d dup! redo rand()\n", arr[i]);
			goto redo;
		}
	}
}

void print_arr(int *arr, int size)
{
	int i;

	for(i = 0; i < size; i++)
		printf("arr[%d] = %d\n", i, arr[i]);
}

int main(void)
{
	int i;
	int data[11] = {0};
	stack *top = NULL;
	int size = sizeof(data) / sizeof(int) - 1;

	srand(time(NULL));

	init_rand_arr(data, size);
	print_arr(data, size);

	for(i = 0; i < size; i++)
		push(&top, data[i]);

	printf("\nNow Popping!\n");

	for(i = 0; i < size; i++)
		printf("%d\n", pop(&top));
	
	return 0;
}
