#include <stdio.h>
#include <string.h>

int where_is_it(char *text, char *find)
{
	int i;

	for(i = 0; text[i]; i++) // 문자열이 끝날 때까지 반복함. 
		if(!(strncmp(&text[i], find, strlen(find))))	//문자열과 찾는 문자열이 동일하면 0을 반환함.
			return i;	// 문자열과 찾는 문자열이 동일한 인덱스 반환
}

int main(void)
{
	int idx;
	char text[100] = "TI Cortex-R5F Safety MCU is very good to Real-Time System.";

	idx = where_is_it(text, "Safety MCU");
	printf("idx = %d\n", idx);

	return 0;
}

/*
문자열에서 찾고자 하는 문자열이 몇번째 부터 시작하는지를 체크함. 
strncmp()함수를 찾아서 전체 문자열과 찾는 문자열을 찾는 문자열의 크기만큼 비교한다. 
*/
