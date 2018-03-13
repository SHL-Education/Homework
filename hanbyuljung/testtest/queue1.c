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
	tmp ->link = EMPTY;
	return tmp;
}

void enqueue(queue **head, int data)
{
	if(*head == NULL)
	{
		*head = get_node();
		(*head) ->data = data;
		return ;
	}
	enqueue(&(*head)->link,data);
}

queue *del_queue(queue *head, int data)
{
	queue *tmp = head;
	if(tmp == NULL)
		printf("값이 없다.");

	if(head->data != data)
		head->link = del_queue(head->link, data);	
	else{
		printf("%d delete!!\n", data);		
		free(tmp);
		return head->link;
	}
	return head;
}

void print(queue *head)
{
	queue *tmp = head;
	while(tmp)
	{
		printf("head->data = %d\n", tmp->data);
		tmp = tmp ->link;
	}
}


int main(void)
{
	queue *head = EMPTY;
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(a)/sizeof(int);
	int i ;
	for(i=0 ; i<len ; i++){
		enqueue(&head, a[i]);
	}
	
	print(head);


	del_queue(head, 3);
	print(head);

	return 0;
}
