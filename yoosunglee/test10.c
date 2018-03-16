#include<stdio.h>

typedef int INT;
typedef int * PINT;

//typedef는 무엇인가? 자료형에 새로운 이름을 부여하고자 할 때 사
// 주로 구조체나 함수 포인터에 사용함

int main(void)
{
	INT num = 3;
	PINT ptr = &num;

	printf("num = %d\n", *ptr);

	return 0;
}
