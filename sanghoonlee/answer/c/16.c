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
	"hkh", "jes", "문지희", "윤연성", "최대성",
	"정상용", "정한별", "하성용", "김형주", "이우석",
	"문한나", "이유성", "박현우", "윤지완", "장성환",
	"이호성", "김민주", "김시윤", "신민철", "은태영",
	"김민호", "유형준", "황수정", "안상재", "정유경",
};

void start_game(int *num, int *exclude_cnt, int *check_cnt)
{
	printf("게임을 몇 명이서 즐기는가 ?");
	scanf("%d", num);
	printf("How many will you exclude ?");
	scanf("%d", exclude_cnt);
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

void set_lose_num(int *cn, int num, int ecnt, int ccnt)
{
	int i;

	for(i = 0; i < ccnt; i++)
	{
redo:
		cn[i] = rand() % (num - ecnt) + 1;

		if(is_dup(cn, i))
		{
			printf("%d dup! redo rand()\n", cn[i]);
			goto redo;
		}
	}
}

void except_name(char **name, int ecnt)
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

//void make_member(m *mem, char *name[2], int num)
void make_member(m *mem, char **name, int num, int ecnt)
{
	int i, j, cnt = 0, chk;

	for(i = 0; i < num; i++)
	{
		chk = 0;

		for(j = 0; j < ecnt; j++)
		{
			if(strcmp(name_tbl[i], name[j]))
				chk++;
			else
			{
				cnt++;
				break;
			}

			if(chk == ecnt)
				strcpy(mem[i - cnt].name, name_tbl[i]);
		}
	}
}

bool is_dup_sm(m *mem, int cur_idx)
{
	int i, tmp = mem[cur_idx].num;

	for(i = 0; i < cur_idx; i++)
		if(tmp == mem[i].num)
			return true;

	return false;
}

void set_game_num(m *mem, int num, int ecnt)
{
	int i;

	for(i = 0; i < num - ecnt; i++)
	{
redo:
		mem[i].num = rand() % (num - ecnt) + 1;

		if(is_dup_sm(mem, i))
		{
			printf("%d dup! redo rand()\n", mem[i].num);
			goto redo;
		}
	}
}

void play_game(m *mem, int *cn, int ln, int ccnt)
{
	int i, j, cnt = 0, chk;

	for(i = 0; i < ln; i++)
		for(j = 0; j < ccnt; j++)
			if(mem[i].num == cn[j])
				printf("You lose: %s\n", mem[i].name);
}

void print_member(m *mem, int num, int ecnt)
{
	int i;

	for(i = 0; i < num - ecnt; i++)
		printf("mem[%d].name = %s\n", i, mem[i].name);
}

void print_info(m *mem, int num, int ecnt)
{
	int i;

	for(i = 0; i < num - ecnt; i++)
		printf("mem[%d].name = %s, mem[%d].num = %d\n", i, mem[i].name, i, mem[i].num);
}

void print_lose_num(int *cn, int ccnt)
{
	int i;

	for(i = 0; i < ccnt; i++)
		printf("lose num: %d\n", cn[i]);
}

int main(void)
{
	int num = 0, check_cnt, exclude_cnt;
	char *name[2] = {NULL, NULL};
	m *mem = NULL;
	int *check_num = NULL;

	srand(time(NULL));

	start_game(&num, &exclude_cnt, &check_cnt);
	setting_game(num, check_cnt, &mem, &check_num);
	//printf("num = %d, exclude_cnt = %d, check_cnt = %d\n", num, exclude_cnt, check_cnt);
	printf("Now start the Ladder Game!\n");

	set_lose_num(check_num, num, exclude_cnt, check_cnt);
	except_name(name, exclude_cnt);
	make_member(mem, name, num, exclude_cnt);
	print_member(mem, num, exclude_cnt);

	set_game_num(mem, num, exclude_cnt);
	print_info(mem, num, exclude_cnt);
	print_lose_num(check_num, check_cnt);

#if 1
	play_game(mem, check_num, num - exclude_cnt, check_cnt);
#endif

	return 0;
}
