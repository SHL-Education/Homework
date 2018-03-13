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
	queue *tmp = *head;
	if( (*head) == NULL){
		*head = get_node();
		(*head)->data= data;
		return ;
	}
	enqueue(&(*head)->link, data);
}
queue *del_queue(queue *head, int data)
{
	queue *tmp = head;
	if(tmp == NULL)
		printf("값이 없습니다.\n");
	if(head->data != data){
		head->link = del_queue((head)->link, data);
	}
	else{
		printf("%d delete !!! \n",data);
		free(tmp);
		return head ->link;
	}
	
	return head;
}
void print(queue *head)
{
	while(head){
		printf("res = %d\n", head->data);
		head = head->link;
	}
}

int main(void)
{
	queue *head = EMPTY;
	int a[]= {1,2,3,4,57,6,5,8,9,7};
	int len = sizeof(a)/sizeof(int);
	int i;
	for(int i;i<len ; i++)
	{
		enqueue(&head, a[i]);
	}
	print(head);
	del_queue(head, 4);
	print(head);

	return 0;
}
