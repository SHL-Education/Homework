#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#define EMPTY 0

typedef struct __queue
{
	int score;
	char *name;
	struct __queue *link;

}queue;

void disp_student_manager(int *score,char *name, int size)
{

	char *str1= "이름과 이름을 입력하시오: ";
	char *str2= "이름과 성적을 입력하시오: ";
	char tmp[32]= {0};


	write(1, str1, strlen(str1));
	read(0, name , size);
	write(1, str2, strlen(str2));
	read(0, tmp, sizeof(tmp));

	*score = atoi(tmp);
	
}
queue *get_queue_node(void)
{
	int len = 


}


void confirm_info(char *name, int score)
{
	printf("학생 이름 = %s", name);
	printf("학생 성적 = %d\n", score);
}

void enqueue(queue **head, char *name, int score)
{
	if(*head == NULL)
	{
		int len = strlen(name);
		(*head) = get_queue_node();
		(*head) -> score = score;
		(*head) ->name = (char*)malloc(len+1);
		strncpy((*head)->name, name, len);
		return;
	}
	enqueue(&(*head)->link, name, score);
}
void print()


int main(void)
{
	int score;
	//Slab 할당자가 32 byre 를 관리하기 때문에 성능이 빠름
	char name[32] = {0};
	queue *head = EMPTY;
	
	disp_student_manager(&score, sizeof(name));
	confirm_info(name, score);
	
	enqueue(&head , name, score);

	return 0;
}
