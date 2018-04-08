#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int cnt;

typedef struct __manage
{
	char *name;
	int score;
	struct __manage *link;
} manage;

manage *make_info(void)
{
	manage *tmp;
	tmp = (manage *)malloc(sizeof(manage));
	tmp->name = NULL;
	tmp->link = NULL;
	return tmp;
}

void set_info(manage **m, char *name, int score)
{
	int size;

	if(*m == NULL)
	{
		*m = make_info();
		(*m)->score = score;
		size = strlen(name);
		(*m)->name = (char *)malloc(size + 1);
		strncpy((*m)->name, name, size);
		cnt++;
		return;
	}

	set_info(&(*m)->link, name, score);
}

int get_total(manage *m)
{
	unsigned int i, sum = 0;
	manage *tmp = m;

	for(i = 0; i < cnt; i++)
	{
		sum += tmp->score;
		tmp = tmp->link;
	}

	return sum;
}

float get_mean(int sum)
{
	return (float)(sum) / (float)cnt;
}

float get_std_dev(manage *m, float mean)
{
	manage *tmp = m;
	unsigned int i;
	float sum = 0;

	for(i = 0; i < cnt; i++)
	{
		sum += pow((float)m->score - mean, 2.0);
		tmp = tmp->link;
	}

	sum /= cnt;
	
	return sqrt(sum);
}

void insert_info(manage **m)
{
	int score = 0;
	char name[30] = {0};

	printf("이름을 입력하라: ");
	scanf("%s", name);

	printf("성적을 입력하라: ");
	scanf("%d", &score);

	set_info(m, name, score);
}

void print_info(manage *m)
{
	manage *tmp = m;

	while(tmp)
	{
		printf("name = %s, score = %d\n", tmp->name, tmp->score);
		tmp = tmp->link;
	}
}

void delete_info(manage **m, char *name)
{
	manage *tmp = *m;

	if(*m == NULL)
		printf("There are no name that you delete: %s\n", name);

	if(strcmp((*m)->name, name) != 0)
		delete_info(&(*m)->link, name);
	else
	{
		printf("Now you delete %s\n", name);
		*m = tmp->link;
		free(tmp);
		cnt--;
	}
}

void sort(manage *arr)
{
	int i, j, key_score;
	char key_name[32];

	printf("cnt = %d\n", cnt);

#if 0
	// 오름차순
	for(i = 1; i < cnt; i++)
	{
		//key_name = arr[i].name;
		strcpy(key_name, arr[i].name);
		key_score = arr[i].score;

		for(j = i - 1; arr[j].score > key_score; j--)
		{
			//arr[j + 1].name = arr[j].name;
			strcpy(arr[j + 1].name, arr[j].name);
			arr[j + 1].score = arr[j].score;
		}

		//arr[j + 1].name = key_name;
		strcpy(arr[j + 1].name, key_name);
		arr[j + 1].score = key_score;
	}
#endif

	// 내림차순
	for(i = cnt - 1; i > 0; i--)
	{
		strcpy(key_name, arr[i - 1].name);
		key_score = arr[i - 1].score;

		for(j = i; arr[j].score > key_score; j++)
		{
			strcpy(arr[j - 1].name, arr[j].name);
			arr[j - 1].score = arr[j].score;
		}

		strcpy(arr[j - 1].name, key_name);
		arr[j - 1].score = key_score;
	}

	printf("Sorting info\n");

	for(i = 0; i < cnt; i++)
		printf("score = %d, name = %s\n", arr[i].score, arr[i].name);
}

/* 사실 cnt 정보가 있으므로 cnt 갯수만큼 malloc 해도됨 */
void sort_info(manage *m)
{
	manage arr[10] = {0};
	manage *tmp = m;
	int len;
	int i;

	for(i = 0; i < cnt; i++)
	{
		len = strlen(tmp->name);
		arr[i].name = (char *)malloc(len + 1);
		strncpy(arr[i].name, tmp->name, len);
		arr[i].score = tmp->score;
		tmp = tmp->link;
	}

	sort(arr);
}

int main(int argc , char *argv[])
{
	int sum, fd,fread;
	char read_buf[1024];
	char name[30] = {0};
	float mean, std_dev;
	manage *m = NULL;


	fd = open( argv[1] , O_CREAT | O_RDWR , 0644);
	while( fread =read(fd, read_buf , sizeof(read_buf))>0 )
	{
		


	}

	set_info(&m, "LSH", 98);
	set_info(&m, "KEH", 92);
	set_info(&m, "LCH", 100);

	sum = get_total(m);

	printf("total = %d\n", sum);

	mean = get_mean(sum);

	printf("mean = %f\n", mean);

	std_dev = get_std_dev(m, mean);

	printf("std_dev = %f\n", std_dev);

	print_info(m);

#if 0
	insert_info(&m);
	print_info(m);

	printf("지울 이름을 입력하시오: ");
	scanf("%s", name);
	delete_info(&m, name);
	print_info(m);
#endif

	sort_info(m);

	return 0;
}
