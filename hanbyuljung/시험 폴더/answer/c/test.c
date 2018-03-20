#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct __member
{
	char name[32];
	int num;
} m;

char *name_tbl[25] = {
	"정상용", "정한별", "하성용", "김형주", "이우석",
	"문한나", "이유성", "박현우", "윤지완", "장성환",
	"문지희", "윤연성", "최대성", "홍현경", "서재언",
	"이호성", "김민주", "김시윤", "신민철", "은태영",
	"김민호", "유형준", "황수정", "안상재", "정유경",
};

void start_game(int *num, int *check_cnt)
{
	printf("게임을 몇 명이서 즐기는가 ?");
	scanf("%d", num);
	printf("몇명이 걸리게 만들것인가 ?");
	scanf("%d", check_cnt);
}

void setting_game(int num, int ccnt, m **mem, int **cnum)
{
	*mem = (m *)malloc(sizeof(m) * num);
	*cnum = (int *)malloc(ccnt);
}

bool is_dup(int *arr, int cur_idx)
{
	int i, tmp = arr[cur_idx];

	for(i = 0; i < cur_idx; i++)
		if(tmp == arr[i])
			return true;

	return false;
}

void set_lose_num(int *cn, int num, int ccnt)
{
	int i;

	for(i = 0; i < ccnt; i++)
	{
redo:
		cn[i] = rand() % num + 1;

		if(is_dup(cn, i))
		{
			printf("%d dup! redo rand()\n", cn[i]);
			goto redo;
		}
	}
}

void except_name(char **name)
{
	int i;
	char n[32] = {0};

	for(i = 0; i < 2; i++)
	{
		printf("제외할 사람 이름을 입력하시오: ");
		scanf("%s", n);
		fflush(stdin);
		getchar();
		name[i] = (char *)malloc(strlen(n));
		strcpy(name[i], n);
	}
}

void make_member(m *mem, char *name[2], int num)
{
	int i, j, cnt = 0;

	for(i = 0; i < num - 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			if(strcmp(name_tbl[i], name[j]))
				strcpy(mem[i - cnt].name, name_tbl[i]);
			else
				cnt++;
		}
	}
}

void play_game(m *mem, int *cn)
{
	printf("제외할 사람 이름을 입력하시오: ");
	
}

void print_member(m *mem)
{
	int i;

	for(i = 0; i < 23; i++)
		printf("mem[%d].name = %s\n", i, mem[i].name);
}

int main(void)
{
	int num = 0, check_cnt;
	char *name[2] = {NULL, NULL};
	m *mem = NULL;
	int *check_num = NULL;

	start_game(&num, &check_cnt);
	setting_game(num, check_cnt, &mem, &check_num);

	set_lose_num(check_num, num, check_cnt);
	except_name(name);
	make_member(mem, name, num);
	print_member(mem);
#if 0
	play_game(mem, check_num);
#endif

	return 0;
}
