#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct __queue
{
	char str[100];
	struct __queue *link;
} queue;

queue *get_node(void)
{
	queue *tmp;
	tmp = (queue *)malloc(sizeof(queue));
	tmp->link = NULL;
	return tmp;
}

void enqueue(queue **head, char str[100])
{
	if(*head == NULL)
	{
		*head = get_node();
		strcpy((*head)->str,str);
		return;
	}

	enqueue(&(*head)->link, str);
}

void print_queue(queue *head)
{
	queue *tmp = head;

	while(head)
	{
		printf("head->data = %s\n", head->str);
		head = head->link;
	}
}
/*
queue *dequeue(queue *head, char *str)
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
*/
int main(void)
{
	int i;
	char *str;

	queue *head = NULL;

	srand(time(NULL));

	for(i = 0; i < 3; i++)
	{
		scanf("%s",str);
		enqueue(&head,str);
	}

	print_queue(head);

	//head = dequeue(head, 10);
	//print_queue(head);

	return 0;
}
