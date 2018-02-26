#include <stdio.h>
int main(void)
{	
	int num = 0 ,last = 0;
	printf("7의배수의 항의갯수를 입력하세요-->");
	scanf("%d",&num);
	last = lastof7(num);
	printf("마지막 항의 값은-->%d",last);
	return 0;
}
int lastof7(int num)
{
	return 7*num;
}
