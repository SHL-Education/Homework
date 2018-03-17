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
	queue *tmp ;
	tmp = (queue*)malloc(sizeof(queue));
	tmp ->link = EMPTY;
	return tmp;
	
}

void enqueue(queue **head, int data)
{
	queue *tmp = *head;
	if(*head == NULL){
		*head = get_node();
		(*head)->data = data;
		return ;
	}
	enqueue(&(*head)->link, data);
}

void print(queue *head)
{
	queue *tmp = head;
	
	while(tmp){
			printf("%d\n",tmp ->data);
			tmp = tmp -> link ;
	}
}

queue *dequeue(queue *head, int data)
{
	queue *tmp = head;


	if(tmp ==NULL)
		printf("값이 없습니다\n");
	
	if( head->data != data){
		head->link = dequeue(head->link,data);
	}
	else{
		printf("%d delete !!!\n",data);
		free(tmp);
		return head ->link;
	}

	return head;
}

int main(void)
{
	queue *head=EMPTY;
	int a[]={3,45,6,7,8,9,42,1,12,13,46,79};
	int len = sizeof(a)/sizeof(int);
	int i;
//	for(int i ; i<len; i++)
//		enqueue(&head, a[i]);
	enqueue(&head, 10);
	enqueue(&head, 20);
	enqueue(&head, 30);
	print(head);
	dequeue(head, 20);
	printf("a\n");
	print(head);

	return 0;
}
