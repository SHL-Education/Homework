#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int score;
	char name[20];
}ST;

typedef struct
{
	int count;
	char name[20];
	// 서버로 만든다. 정해진 크기를 먼저 할당해주고 
	// 구조체의 끝이자 새로운 시작이다. 형체가 없는것, 주소는 있다.
	int score[0];
}FLEX;

int main(void)
{
	// 할당받는 속도가 없어진다. 그래서빨라진다.
	// 원래는 할당받고 해제하는시간때매 느려지고 그런다.
	// 여러개를 한다고 하면 엄청 동적할당을 한다. 
	// 그래서 10만개 정도 돌리면 안되는데
	// 미리 정해주면 안좋은 점은 이미 있던 메모리를 칠 수도 있다.
	FLEX *p = (FLEX*)malloc(4096);
	int i = 0;
	p->score[0] = 0;
//	p->score[1] = 20;
//	printf("%d",sizeof(FLEX));


	for(i = 0 ;i <100 ;i++){
		p->score[i] = i+1;
		printf("%d\n",p->score[i]);
	}
	return 0;
}

