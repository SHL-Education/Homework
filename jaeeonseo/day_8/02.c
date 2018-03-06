#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0	

typedef struct __queue
{
	int data;
	struct __queue *link;

}queue;


void enqueue(queue **head, int data)
{

	queue *tmp;

	if(*head == NULL)
	{
		*head =	(queue *)malloc(sizeof(queue));
		(*head)->data = data;
		
 		return;
	}

	tmp = (queue *)malloc(sizeof(queue));

	tmp->data = data;

	(*head)->link = tmp;

}


int dequeue(queue **head)
{
	queue *tmp;

	int data;

	tmp = *head;

	data = tmp->data;

	*head = tmp->link;

	free(tmp);

	return data;

}


int main(void)
{

	queue *head = EMPTY;

	enqueue(&head, 10);
	enqueue(&head, 20);

	printf("%d st: %d\n",1, dequeue(&head));
	printf("%d st: %d\n",2, dequeue(&head));


	return 0;
}
	

