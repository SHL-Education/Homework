#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//char tmp[32] = {0};

typedef struct __queue
{
	int score;
	char *name;
	struct __queue *link;
} queue;

void disp_student_manager(int *score, char *name, int size)
{
	char *str1 = "학생 이름을 입력하시오: ";
	char *str2 = "학생 성적을 입력하시오: ";
	char tmp[32] = {0};

	write(1, str1, strlen(str1));
	read(0, name, size);
	write(1, str2, strlen(str2));
	read(0, tmp, sizeof(tmp));
	
	*score = atoi(tmp);
}

void confirm_info(char *name, int score)
{
	printf("학생 이름 = %s\n", name);
//	printf("학생 성적 = %s\n", tmp);
	printf("학생 성적 = %d\n", score);
}

queue *get_queue_node(void)
{
	queue *tmp;

	tmp = (queue *)malloc(sizeof(queue));
	tmp->name = NULL;
	tmp->link = NULL;

	return tmp;
}

void enqueue(queue **head, char *name, int score)
{
	if(*head == NULL)
	{
		int len = strlen(name);
		(*head) = get_queue_node();
		(*head)->score = score;
		(*head)->name = (char *)malloc(len + 1);
		strncpy((*head)->name, name, len);
		return;
	}

	enqueue(&(*head)->link, name, score);
}

void print_queue(queue *head)
{
	queue *tmp = head;

	while(tmp)
	{
		printf("name = %s, score = %d\n", tmp->name, tmp->score);
		tmp = tmp->link;
	}
}

void remove_enter(char *name)
{
	int i;

	for(i = 0; name[i]; i++)
		if(name[i] == '\n')
			name[i] = '\0';
}

int main(void)
{
	int cur_len, fd, btn = 0;
	int score;

	// Slab 할당자가 32 byte 를 관리하기 때문에 성능이 빠름
	char name[32] = {0};
	char str_score[32] = {0};
	char buf[64] = {0};

	queue *head = NULL;

	for(;;)
	{
		printf("1 번: 성적 입력, 2 번: 파일 저장, 3 번: 파일 읽기, 4 번: 종료\n");
		scanf("%d", &btn);

		switch(btn)
		{
			case 1:
				disp_student_manager(&score, name, sizeof(name));
				remove_enter(name);
				confirm_info(name, score);

				enqueue(&head, name, score);
				print_queue(head);
				break;

			case 2:
				// 만약 파일 없다면 생성
				// 있다면 불러서 추가
				if((fd = open("score.txt", O_CREAT | O_EXCL | O_WRONLY, 0644)) < 0)
					fd = open("score.txt", O_RDWR | O_APPEND);

				/* 어떤 형식으로 이름과 성적을 저장할 것인가 ?
				   저장 포맷: 이름,성적\n */
				strncpy(buf, name, strlen(name));
				cur_len = strlen(buf);
				//printf("cur_len = %d\n", cur_len);
				buf[cur_len] = ',';
				sprintf(str_score, "%d", score);
				strncpy(&buf[cur_len + 1], str_score, strlen(str_score));
				buf[strlen(buf)] = '\n';
				//printf("buf = %s, buf_len = %lu\n", buf, strlen(buf));

				write(fd, buf, strlen(buf));

				close(fd);
				
				break;

			case 3:
				if((fd = open("score.txt", O_RDONLY)) > 0)
				{
					int i, backup = 0;
					// 이름1,성적1\n
					// 이름2,성적2\n
					// ......
					// 이름n,성적n\n
					read(fd, buf, sizeof(buf));
					
					for(i = 0; buf[i]; i++)
					{
						if(!(strncmp(&buf[i], ",", 1)))
						{
							strncpy(name, &buf[backup], i - backup);
							backup = i + 1;
						}
						if(!(strncmp(&buf[i], "\n", 1)))
						{
							strncpy(str_score, &buf[backup], i - backup);
							backup = i + 1;
							enqueue(&head, name, atoi(str_score));
						}
					}

					print_queue(head);
				}
				else
					break;

				break;

			case 4:
				goto finish;
				break;

			default:
				printf("1, 2, 3, 4 중 하나 입력하셈\n");
				break;
		}
	}

finish:
	return 0;
}
