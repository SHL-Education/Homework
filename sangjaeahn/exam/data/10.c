#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#define EMPTY 0

struct node{
	int data;
	struct node *link;
};
typedef struct node Stack;

Stack *get_node()
{
	Stack *tmp;
	tmp=(Stack *)malloc(sizeof(Stack));
	tmp->link=EMPTY;
	return tmp;
}
void push(Stack **top, int data)
{
	Stack *tmp;
	tmp = *top;
	*top = get_node();
	(*top)->data = data;
	(*top)->link = tmp;
}

int pop(Stack **top)
{
	Stack *tmp;
	int num;
	tmp = *top;
	
	if(*top == EMPTY)
	{
		printf("Stack is empty!!!\n");
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
		//arr[i] = rand() % 15 + 1;
		arr[i] = (rand() % 100) +1;

		if(is_dup(arr, i))
		{
			printf("%d dup! redo rand()\n", arr[i]);
			goto redo;
		}
	}
}

int main(void)
{
	Stack *top = EMPTY;
	
	int arr[20] = {0,};
	int size = sizeof(arr)/sizeof(int);
	int i;

	srand(time(NULL));
	init_rand_arr(arr, size);
	
	for(i=0;i<size;i++)
	{
		push(&top, arr[i]);
	}
	
	for(i=0;i<size+1;i++)
	{
		printf("%d\n", pop(&top));
	}	
	return 0;
}
