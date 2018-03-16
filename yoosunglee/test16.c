#include<stdio.h>

// 구조체는 왜 사용하는가?

// 자료를 처리하다 보니 하나로 묶어야 편함 문자열과 숫자를 한 번에 묶어서 관리하고 싶을 때 등

typedef struct pos{
	
	double x_pos;
	double y_pos;
}INT;

// 구조체는 내가 원하는 식으로 자료형을 만든다.

int main(void)

{
	double num;
	
	INT position;		//int *a 껍데기 안생겼다가 int *a = &~~ 넣었을 때 껍데기가 생긴다.
				//메모리에 생성 안되었다가 생성됨,
	int a;
	

	num = 1.2;
	position.x_pos = 3.3;
	position.y_pos = 7.7;

	printf("sizeof(position) = %d\n",sizeof(position));
	printf("%lf , %lf \n" , position.x_pos,position.y_pos);

	//double = lf %d는 정수형이니 %lf 로

	return 0;

}

