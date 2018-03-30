#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

#define EMPTY 0

typedef struct __queue
{
	int data;
	struct __queue *link;
}
queue;

queue *get_node()
{
	queue *tmp;
	tmp = (queue*)malloc(sizeof(queue));
	tmp -> link = EMPTY;
	return tmp;
}

void enqueue(queue **head, int data)
{
	queue *tmp = *head;
	if(*head == NULL)
	{
		(*head) = get_node();
		(*head)->data = data;
		return ;
	}
	enqueue(&(*head)->link, data);
}
void dequeue(queue **head, int data)
{
	queue *tmp = *
	if(*head == NULL)
	{
		printf("값이 없습니다.\n");
		return ;
	}
	else if( (*head)->data == data))
	{
		*head = (*head)->link;
		free(tmp);
	}





}
