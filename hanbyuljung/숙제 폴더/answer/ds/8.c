#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
		//queue *res = head->link;
		printf("Now you delete %d\n", data);
		*head = tmp->link;
		free(tmp);
	}
}

bool is_dup(int *arr, int cur_idx)
{
	int i, tmp = arr[cur_idx];

	for(i = 0; i < cur_idx; i++)
		if(tmp == arr[i])
			return turue;

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
	int data[10] = {};
	int size = sizeof(data) / sizeof(int) - 1;

	queue *head = NULL;

	srand(time(NULL));

	init_rand_arr(arr, size);
	print_arr(arr, size);

	for(i = 0; i < 3; i++)
		enqueue(&head, (i + 1) * 10);

	print_queue(head);

	dequeue(&head, 20);

	print_queue(head);

	return 0;
}
