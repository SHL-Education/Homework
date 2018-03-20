#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	
	char a;
	printf("알파벳을 입력하시오\n");
	scanf("%c", &a);
	if(a>='a')
		printf("소문자%c 를 바꾼 대문자 %c\n",a, a-32);
	else
		printf("대문자 %c를 바꾼 소문자 %c\n",a, a+32);

	return 0;
}	
