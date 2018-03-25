#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct __queue
{
	int data;
	struct __queue *link;
} queue;

queue *get_node(void)
{
	queue *tmp;
	tmp = (queue *)malloc(sizeof(queue));
	tmp->link = NULL;
	return tmp;
}

void enqueue(queue **head, int data)
{
	if(*head == NULL)
	{
		*head = get_node();
		(*head)->data = data;
		return;
	}

	enqueue(&(*head)->link, data);
}

void print_queue(queue *head)
{
	queue *tmp = head;

	while(head)
	{
		printf("head->data = %d\n", head->data);
		head = head->link;
	}
}

void dequeue(queue **head, int data)
{
	queue *tmp = *head;

	if(*head == NULL)
		printf("There are no data that you delete\n");

	if((*head)->data != data)
		dequeue(&(*head)->link, data);
	else
	{
		printf("Now you delete %d\n", data);
		*head = tmp->link;
		free(tmp);
	}
}

bool is_dup(int *arr, int cur_idx)	// arr배열의 중복을 체크함.
{
	int i, tmp = arr[cur_idx];

	for(i = 0; i < cur_idx; i++)
		if(tmp == arr[i])
			return true;

	return false;
}

void init_rand_arr(int *arr, int size)	// arr배열을 초기화함.
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
	int arr[10] = {};
	int size = sizeof(arr) / sizeof(int) - 1;	// arr 배열의 크기를 구함.

	queue *head = NULL;

	srand(time(NULL));

	init_rand_arr(arr, size);	// arr배열에 1~100의 수를 랜덤으로 젖아함.
	print_arr(arr, size);	// arr배열의 모든 원소를 출력함.

	for(i = 0; i < 3; i++)
		enqueue(&head, (i + 1) * 10);	// 10,20,30 의 data를 차례로 queue에 저장함.

	print_queue(head);	// queue의 모든 data 값을 출력함.

	dequeue(&head, 20);	// queue의 data중에서 20을 삭제함.

	print_queue(head);	// queue의 모든 data 값을 출력함.

	return 0;
}

/*
재귀함수를 통한 큐의 구현
삽입, 삭제, 출력 구현
*/
