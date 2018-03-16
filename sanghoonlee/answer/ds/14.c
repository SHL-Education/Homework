#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct __queue
{
	//int data;
	char *data;
	struct __queue *link;
} queue;

queue *get_node(void)
{
	queue *tmp;
	tmp = (queue *)malloc(sizeof(queue));
	tmp->link = NULL;
	return tmp;
}

void enqueue(queue **head, char *data)
{
	int size;

	if(*head == NULL)
	{
		*head = get_node();
		size = strlen(data);
		(*head)->data = (char *)malloc(size + 1);
		strncpy((*head)->data, data, size);
		//(*head)->data = data;
		return;
	}

	enqueue(&(*head)->link, data);
}

void print_queue(queue *head)
{
	queue *tmp = head;

	while(head)
	{
		printf("head->data = %s\n", head->data);
		head = head->link;
	}
}

int main(void)
{
	int i;

	queue *head = NULL;
	char *data[3] = {"Hello", "Hi", "Gom Bang Wa"};

	srand(time(NULL));

	for(i = 0; i < 3; i++)
		enqueue(&head, data[i]);

	print_queue(head);

	return 0;
}
