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
}queue;

queue *get_node()
{
	queue *tmp;
	tmp = (queue*)malloc(sizeof(queue));
	tmp->link = EMPTY;
	return tmp;
}


void enqueue(queue **head, int data)
{
	queue *tmp = *head;
	if(*head == NULL)
	{
		*head = get_node();
		(*head)->data = data;
		return ;
	}
	enqueue(&((*head)->link), data);
}

/*
queue *dequeue(queue **head, int data)
{
	queue *tmp = head;
	if(*head == NULL)
	{
		printf("값이 없습니다.");
		return *head;
	}
	else if(head->data != data)
	{
		(*head)->link = dequeue(&head);
	}
	else {
		printf("delete %d\n", data);
		tmp = tmp ->link;
		free(tmp);
		return (*head)->link;
	}
	return head;
}
void print(queue *haed)
{


	
}
*/
void print(int *arr, int size)
{
	int i;
	for(i=0; i<size ; i++)
		printf("arr[%d] = %d \n",i, arr[i]);

}
int rand_non_same(int *arr)
{
	int i,buf, res;
	int tmp[10];
	int j=0;
	buf = 0;
	
	srand(time(NULL));
	while(buf < 10)
	{
		//첨에 값을 받고
		res = rand()%10+1;

		// 값을 받을것을 현재 버퍼가 차있는 곳 까지 검색을 한다.
		// 검색중에 
		// 찾는데 마지막 버퍼 위치까지 없을 때 그 값을 다음 버퍼 위치에 저장한다.
		for(i=0; i < 10 ; i++)
		{
			if(res == arr[i]){
				//printf("check1\n ");
				break ;
			}

			else if(i == buf){
				//printf("check2 buf %d\n",buf);
				arr[buf++] = res;
				break;
			}
		}
	}
}

int even_num(int *arr,int len)
{
	int num=0,i=0;

	for(i =0; i<len ;i++)
		if(arr[i]%2 == 0) num += arr[i];

	return num;
}

int main(int argc , char **argv)
{
	queue *head = EMPTY;
	int arr[10]={0};
	int i=0;
	int fd,fd2,fread,buf[1024],even;
	int len = sizeof(arr) / sizeof(int);
	char read_buf[1024];

	fd = open(argv[1] , O_RDWR | O_CREAT | O_TRUNC ,0644);
//	fd2 = open(argv[1] ,O_RDONLY | O_TRUNC,0644);

	rand_non_same(arr);
	print(arr, len);


	printf("\n");

	for(i =0 ;i <len ;i++)
	{
		enqueue(&head, arr[i]);
	}
	printf("다 출력 하였습니다.\n");

	even = even_num(arr, len);

	printf("%d\n",even);
	
	for(i=0; i<len; i++){
		sprintf(read_buf,"%d \n", arr[i]);
		write(fd, read_buf, strlen(read_buf));
	}

	sprintf(read_buf,"\n 짝수의 합 = %d \n", even);
	write(fd, read_buf, strlen(read_buf));
	
	lseek(fd , 0, SEEK_SET);

	fread = read(fd, buf, sizeof(buf));
//	fread = read(fd2, buf, sizeof(buf));
	write(1 , buf ,fread);

	close(fd);
	return 0;
}
