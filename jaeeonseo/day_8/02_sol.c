#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct __queue{

	int data;
	struct __queue *link;

}queue;


void print_queue(queue *head)
{
	queue *tmp;

	tmp = head;

	if(tmp == NULL)
	{
		printf("queue is now empty\n");
	}

	for( ; tmp != NULL; )
	{
		printf("data:%d\n", tmp->data);
		tmp = tmp->link;
	}
	
}

void enqueue(queue *head, int data)
{
	queue *tmp;

	if(head == NULL)
	{
		head = (queue *)malloc(sizeof(queue));
		head->data = data;
		
		return;
	}

	tmp = (queue *)malloc(sizeof(queue));
	
	tmp->data = data;

	head->link = tmp;
		
}


queue *dequeue(queue *head, int data)
{
	queue *tmp = head;

	if(tmp == NULL)
		printf("There are no data that you delete\n");

	if(tmp->data != data)
		tmp = dequeue(tmp->link, data);
	else
	{
		printf("Now you delete %d\n", data);
		free(tmp);
		return tmp->link;
	}

	return tmp;
}

int main(void)
{
	int i;

	queue *head = NULL;

	srand(time(NULL));

	for(i=0; i <3; i++)
		enqueue(&head, (i+1)*10);

	print_queue(head);

	head = dequeue(head, 20);

	print_queue(head);

	return 0;
}
