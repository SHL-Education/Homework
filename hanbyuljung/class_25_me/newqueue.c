#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>


#define EMPTY 0
#define SIZE 10

int flag=0;


typedef struct __queue
{
	int data[0];
	int dflag[0];
}queue;

queue *get_node()
{
	queue *tmp;
//	if(flag == 0){
//		tmp = (queue*)malloc(4096);
//		flag =1;
//	}
	return tmp ;
}

int enqueue(queue **head, int data, int index)
{
//	queue *tmp = *head;
	(*head)->data[index] = data;
	return index+1;
}

void print(queue **head,int dindex)
{
	int i=0;
	int x=0;
	printf("\n");
	for(i = 0; i<SIZE+dindex; i++)
	{
		if(i==(*head)->dflag[x]){		
			x++;
			continue;
		}
		printf("data[%d]=[%d]\n",i,(*head)->data[i]);

	}
}

int dequeue(queue **head, int data, int dindex)
{
	int i=0;
	for(i =0; i<SIZE; i ++)
	{
		if((*head)->data[i] == data){
			printf("\n%d는 %d번째 입니다. 지우겠습니다.\n",data,i+1);
			(*head)->data[i] = 0;

			(*head)->dflag[dindex]= i;
			printf("dflag 의 갯수:%d\n",++dindex);
			// 지울때의 dflag 에는 index i의 값을 넣는다.
		}
	}
	return dindex;
}



int main(void)
{
	queue *head = (queue*)malloc(4096);
//	queue *head = EMPTY;
	int i=0;
	int index =0;
	int dindex = 0;
	int insert=3;

//	srand(time(NULL));
	for(i=0;i<SIZE; i++)
		index = enqueue(&head, rand()%20+1,index);
	print(&head,dindex);
	dindex = dequeue(&head,18,dindex);
	print(&head,dindex);
	printf("\n%d를 집어 넣겠습니다.\n",insert);
	index = enqueue(&head, insert, index);
	print(&head,dindex);
	
	dindex = dequeue(&head,10,dindex);
	print(&head,dindex);

	return 0;
}

