#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	int data;
	int idx;
}
queue;

typedef struct
{

	int full_num;
	int free_num;
	int total;
	int cur_idx;
	// free idx
	int free[1024];
	int total_free;
	// 진짜 돌아갈 배열
	queue head[0];
}
manager;

bool is_dup(int *arr, int cur_idx)
{
	int i, tmp = arr[cur_idx];

	for(i = 0; i < cur_idx; i++)
		if(tmp == arr[i])
			return true;

	return false;
}

void init_data(int *data, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
redo:
		data[i] = rand() % 100 + 1;

		if(is_dup(data, i))
		{
			printf("%d dup! redo rand()\n", data[i]);
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

void init_manager(manager *m, int alloc_size)
{
	m->full_num = 0;
	// 12: full_num, free_num, cur_idx
	// 8: data, idx
	// 할당할수 있는 개수는 1533이다
	m->free_num = (alloc_size / sizeof(int) - 1029) / 2;
	m->total = (alloc_size / sizeof(int) - 1029) / 2;
	m->cur_idx = 0;
}

void print_manager_info(manager *m)
{
	int i;

	printf("m->full_num = %d\n", m->full_num);
	printf("m->free_num = %d\n", m->free_num);
	printf("m->total = %d\n", m->total);
	printf("m->cur_idx = %d\n", m->cur_idx);
	printf("m->total_free = %d\n", m->total_free);

	for(i = 0; i < m->total_free; i++)
		printf("m->free = %d\t", m->free[i]);

	printf("\n");
}

void enqueue(manager *m, int data)
{
	m->head[m->cur_idx].data = data;
	m->head[m->cur_idx++].idx = m->cur_idx;
	m->free_num--;
	m->full_num++;
}

void dequeue(manager *m, int data)
{
	int i;

	for(i = 0; i < m->full_num; i++)
	{
		if(m->head[i].data == data)
		{
			m->head[i].data = 0;
			m->head[i - 1].idx = m->head[i].idx;
			m->free_num++;
			m->full_num--;
			m->free[m->total_free++] = i;
		}
	}
}

void print_queue(manager *m)
{
	int i = 0;
	int flag = 0;
	int tmp = i; // m->head[i].idx;

	printf("print_queue\n");

#if 0
	for(; !(m->head[tmp].data);)
		tmp = m->head[tmp].idx;
#endif

	while(m->head[tmp].data)
	{
		printf("data = %d, cur_idx = %d\n", m->head[tmp].data, tmp);
		printf("idx = %d\n", m->head[tmp].idx);

		for(; !(m->head[tmp].data);)
		{
			tmp = m->head[tmp].idx;
			flag = 1;
		}

		if(!flag)
			tmp = m->head[tmp].idx;

		flag = 0;
	}
}

bool is_it_full(manager *m)
{
	if(m->full_num < m->cur_idx)
		return true;

	return false;
}

void enqueue_with_free(manager *m, int data)
{
	/*
			m->head[i].data = 0;
			m->head[i - 1].idx = m->head[i].idx;
			m->free_num++;
			m->full_num--;
			m->free[m->total_free++] = i;
	*/

	m->head[m->cur_idx - 1].idx = m->free[m->total_free - 1];
	m->total_free--;
	m->head[m->free[m->total_free]].data = data;
	m->head[m->free[m->total_free]].idx = m->free[m->total_free - 1];

	if(!(m->total_free - 1 < 0))
		m->head[m->free[m->total_free]].idx = m->free[m->total_free - 1];
	else
		printf("Need more memory\n");

	m->free_num--;
	m->full_num++;
}

int main(void)
{
	int i;
	bool is_full;
	// 4096을 할당한다.
	int alloc_size = 1 << 12;
	int data[10] = {0};
	int size = sizeof(data) / sizeof(int);

	srand(time(NULL));
	init_data(data, size);
	print_arr(data, size);

	// 메모리를 할당한다.
	manager *m = (manager *)malloc(alloc_size);
	init_manager(m, alloc_size);
	printf("Before Enqueue\n");
	print_manager_info(m);

	for(i = 0; i < size; i++)
		enqueue(m, data[i]);

	printf("After Enqueue\n");
	print_queue(m);

	dequeue(m, data[1]);

	printf("After Dequeue\n");
	print_queue(m);

	enqueue(m, 777);
	print_manager_info(m);
	print_queue(m);

	dequeue(m, data[4]);
	dequeue(m, data[5]);
	dequeue(m, data[6]);
	enqueue(m, 333);
	print_manager_info(m);
	print_queue(m);

#if 1
	// 강제로 꽉찼다 가정하고 free 공간을 활용 해보자!
	is_full = true;
#endif

	//if(is_it_full(m))
	if(is_full)
		enqueue_with_free(m, 3333);

	print_manager_info(m);
	print_queue(m);

	return 0;
}
