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
		printf("Now you delete %d\n", data);
		*head = tmp->link;
		free(tmp);
	}
}

int main(void)
{
	int i;
	queue *head = NULL;

	for(i = 0; i < 2; i++)
		enqueue(&head, (i + 1) * 10);

	print_queue(head);

	return 0;
}

/*
8번과 동일
*/
