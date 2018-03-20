#include<stdio.h>
#include<malloc.h>

#define EMPTY 0

typedef struct __queue
{
	int data;
	struct __queue *link;
}queue;

queue *get_node()
{
	queue *tmp;
	tmp = (queue*)malloc(sizeof(queue));
	tmp -> link = EMPTY;
	return tmp;
}

void enqueue(queue **head, int data)
{
	if(*head == NULL)
	{
		*head = get_node();
		(*head)->data = data;
		return ;
	}
	enqueue(&((*head)->link), data);
}

void print(queue *head)
{

	queue *tmp = head;
	while(tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->link;
	}

}

queue *dequeue(queue *head  , int data)
{
	queue *tmp = head;
	if(head== NULL){
		printf("값이 없습니다.");
		return 0;
	}
	else if(head->data != data)
	{
		head->link = dequeue(head->link , data);
	}
	else{ 
		printf("%d Now delete!!!",data);
		free(tmp);
		return head->link;
	}
	return head;
		

}
int main(void)
{
	queue *head = EMPTY;
	
	
	enqueue(&head, 10);
	enqueue(&head, 20);

	print(head);
	dequeue(head, 10);
	print(head);

	return 0;
}
