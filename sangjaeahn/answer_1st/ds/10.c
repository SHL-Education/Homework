#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct __stack
{
	int data;
	struct __stack *link;
} stack;

stack *get_stack_node(void)	// push를 할때 새로운 노드를 생성함.
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
	*top = get_stack_node();    // 노드를 만듬.
	(*top)->data = data;	// data를 생성한 노드의 data에 저장함.
	(*top)->link = tmp;	// 생성한 노드를 top으로 만듬
}

int pop(stack **top)
{
	stack *tmp;
	int num;
	tmp = *top;

	if(*top == NULL)	// top이 없으면 애초에 스택에 노드가 없다는 것
	{
		printf("Stack is empty\n");
		return 0;
	}

	num = tmp->data;	// top의 data를 빼냄.
	*top = (*top)->link;	// top을 top->link로 대체함.
	free(tmp);		// top 노드 제거함.

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

void init_rand_arr(int *arr, int size)	// 배열을 초기화함.
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

void print_arr(int *arr, int size)	// 배열의 모든 원소를 출력함.
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

	init_rand_arr(data, size);	// data배열을 1~100의 숫자로 랜덤으로 셋팅함.
	print_arr(data, size);		// data배열의 원소를 출력함.

	for(i = 0; i < size; i++)
		push(&top, data[i]);	// data배열의 원소를 스택에 push함.

	printf("\nNow Popping!\n");

	for(i = 0; i < size; i++)
		printf("%d\n", pop(&top));	// 스택에 있는 노드들을 pop해서 출력함.
	
	return 0;
}

/*
스택 구현
push, pop 구현
*/
