#include <stdio.h>

/*
문제:단 한 번의 연산으로 대소문자 전환을 할 수 있는 연산에 대해 기술하시오.
*/
int main(void)
{
	char a = 'a';
	
	printf("%c\n", a);
	printf("%c\n", a^32);
	
	return 0;
}

/* 결과값
a
A
*/ 
