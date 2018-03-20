#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>

#define EMPTY 0

typedef struct __queue
{
	int data;
	struct __queue *link;

}queue;


queue *get_node()
{
	queue *tmp;
	tmp = (queue *)malloc(sizeof(queue));
	tmp -> link = EMPTY;
	return tmp;
}

void print(queue *head){

	queue *tmp=head;


	while(tmp){
		printf("값 : %d\n", tmp->data);
		tmp = tmp ->link;
	}

}

void enqueue(queue **head, int data)
{
	if(*head == NULL)
	{
		*head = get_node();
		(*head) -> data =data;

		//	printf("%d\n",data);
		return ;
	}

	enqueue(&((*head)->link),data);
}



int main(void)
{
	//int data=10;
	queue *head=EMPTY;
	int i;
	int arr[16]={0};
	srand(time(NULL));
	for(i=0;i<16;i++)
	{
		arr[i]=rand()%16;
		enqueue(&head, arr[i]);
	}

	print(head);
	return 0;
}
