#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <unistd.h>
#include <fcntl.h>

int extract_idx;

typedef struct __queue
{
	int data;
	struct __queue *link;
} queue;

bool is_dup(int *arr, int cur_idx)
{
	int i, tmp = arr[cur_idx];

	for(i = 0; i < cur_idx; i++)
		if(tmp == arr[i])
			return true;

	return false;
}

void init_rand_arr(int *arr, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
redo:
		arr[i] = rand() % 10 + 1;

		if(is_dup(arr, i))
		{
			printf("%d dup! redo rand()\n", arr[i]);
			goto redo;
		}
	}
}

void print_arr(int *arr, int size)
{
	int i;

	for(i = 0; i < size; i++)
		printf("arr[%d] = %d\n", i, arr[i]);
}

queue *get_queue_node(void)
{
	queue *tmp;
	tmp = (queue *)malloc(sizeof(queue));
	tmp->link = NULL;
	return tmp;
}

void enqueue(queue **head, int data)
{
	if(*head == NULL)
	{
		*head = get_queue_node();
		(*head)->data = data;
		return;
	}

	enqueue(&(*head)->link, data);
}

void extract_even(queue *head, int *extract)
{
	queue *tmp = head;

	while(tmp)
	{
		if(!(tmp->data % 2))
			extract[extract_idx++] = tmp->data;
		tmp = tmp->link;
	}
}

int main(void)
{
	int i, fd, len, sum = 0;
	char *convert[10] = {0};
	int arr[11] = {0};
	char tmp[32] = {0};
	int extract[11] = {0};
	int size = sizeof(arr) / sizeof(int) - 1;
	queue *head = NULL;

	srand(time(NULL));

	init_rand_arr(arr, size);
	print_arr(arr, size);

	for(i = 0; i < size; i++)
		enqueue(&head, arr[i]);

	extract_even(head, extract);
	printf("\nExtract:\n");
	print_arr(extract, extract_idx);

	fd = open("log.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

	for(i = 0; i < extract_idx; i++)
		sum += extract[i];

	sprintf(tmp, "%d", sum);
	write(fd, tmp, strlen(tmp));
	close(fd);

#if 0
	for(i = 0; i < extract_idx; i++)
	{
		int len;
		char tmp[32] = {0};

		sprintf(tmp, "%d", extract[i]);
		len = strlen(tmp);
		convert[i] = (char *)malloc(len + 1);
		strcpy(convert[i], tmp);
		printf("tmp = %s\n", tmp);
	}
#endif

	return 0;
}
