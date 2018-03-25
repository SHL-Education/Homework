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
		size = strlen(data);	// data의 크기를 구함.
		(*head)->data = (char *)malloc(size + 1);	// (*head)->data 에 size+1 크기 만큼의 메모리를 만듬. 
		strncpy((*head)->data, data, size);	// data를 노드의 data공간에 저장함.
		return;
	}

	enqueue(&(*head)->link, data);
}

void print_queue(queue **head)	
{
	queue **tmp = head;

	while(*tmp)
	{
		printf("head->data = %s\n", (*tmp)->data);
		*tmp = (*tmp)->link;
	}
}

int main(void)
{
	int i;

	queue *head = NULL;
	char *data[3] = {"Hello", "Hi", "Gom Bang Wa"};

	srand(time(NULL));

	for(i = 0; i < 3; i++)
		enqueue(&head, data[i]);  // data배열의 각원소의 주소를 삽입함.

	print_queue(&head);	// queue의 모든 데이터를 출력함.

	return 0;
}

/*
문자열 데이터로 queue를 만듬.
*/
