#include<stdio.h>
#include<malloc.h>


#define EMPTY 0

typedef struct __nod
{
	int data;
	struct __nod *link;

}queue;


queue *get_node()
{
	queue *tmp;
	tmp = (queue *)malloc(sizeof(queue));
	tmp -> link = EMPTY;
	return tmp;
}

void print(queue *head)
{
	queue *tmp;
	tmp = head;

	while(tmp)
	{
		printf("값: %d\n", tmp -> data );
		tmp = tmp ->link;
	}

}


void enqueue(queue **head, int data)
{

	if(*head == NULL){
		*head = get_node();
		(*head) -> data =data;
		return ;
	}
	enqueue(&((*head)->link),data);
}


int main(void)
{
	queue *head = EMPTY;
	enqueue(&head, 10);
	enqueue(&head, 20);
	enqueue(&head, 30);

	print(head);

}
