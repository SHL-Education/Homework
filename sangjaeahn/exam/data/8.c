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

queue *dequeue(queue *head, int data)
{
	queue *tmp = head;

	if(tmp == NULL)
		printf("There are no data that you delete\n");

	if(head->data != data)
		head->link = dequeue(head->link, data);
	else
	{
		printf("Now you delete %d\n", data);
		free(tmp);
		return head->link;
	}

	return head;
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
again:
		arr[i] = rand()%16;

		if(is_dup(arr, i))
		{
			printf("%d dup! redo rand()\n", arr[i]);
			goto again;
		}
	}
}

int main(void)
{
	int i, arr[16] = {0,};
	int size = sizeof(arr)/sizeof(int);

	queue *head = NULL;

	srand(time(NULL));
	init_rand_arr(arr, size);
	
	for(i = 0; i < size; i++)
		enqueue(&head, arr[i]);

	print_queue(head);

	head = dequeue(head, 10);

	print_queue(head);

	return 0;
}
