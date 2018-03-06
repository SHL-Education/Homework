#include <stdio.h>
#include <malloc.h>
#include <time.h>

#define EMPTY 0

typedef struct __queue
{
	int data;
	struct __queue *link;

}queue;

queue *get_node(){

	queue *tmp;
	tmp = (queue *)malloc(sizeof(queue));
	tmp -> link = EMPTY;

	return tmp;
}

void enqueue(queue **head, int data){
	
	if(*head == NULL){
		*head = get_node();
		(*head) -> data = data;
		
		return ;
	}
	
	enqueue(&((*head)->link),data);
}
void print_queue(queue *head)
{
	queue *tmp;
	tmp = head;
	while(tmp)
	{
		printf("%d\n", tmp -> data);
		tmp = tmp ->link;
	}

}
void queue_delete(queue *head,int data)
{
	queue *tmp;
	tmp = head;
	while(tmp)
	{
		if((tmp -> data) == data){
		//	printf("같습니다.%d\n",data);
			tmp = tmp ->link;
		}
		else
		{
			printf("%d\n", tmp->data);
			tmp = tmp ->link;
		}
	}
}

void queue_delete2(queue *head, int data)
{
	queue *tmp;
	tmp = head;
	if((tmp->data) == data)
	{
		head -> link = tmp -> link;
		printf("같습니다.\n");
		free(tmp);
	}
	else if((tmp->data) != data)
	{
		head->link = tmp -> link;
		printf("res = %d\n", tmp -> data);
	}
	else
			return ;

	queue_delete2( (tmp->link) , data);
}

queue *queue_delete3(queue *head, int data)
{
	queue *tmp = head;

	if(tmp ==NULL)
			printf("There are no data that you delete\n");
	if(head ->data != data)
			head ->link = queue_delete3(head->link, data);
	else 
	{
			// queue *res = head ->link;
			printf("Now you delete %d\n",data);
			free(tmp);
			return head->link;
	}
	return head;
}

int main(void){
	
	queue *heap = EMPTY;
//	srand(time(NULL));
	enqueue(&heap, 10);
	enqueue(&heap, 20);
	enqueue(&heap, 30);
	print_queue(heap);
	queue_delete3(heap,20);
//	heap = queue_delete3(heap,20);
//	queue_delete2(heap,20);
//	print_queue(heap);
//	queue_delete(heap,20);

	print_queue(heap);

	return 0;
}
