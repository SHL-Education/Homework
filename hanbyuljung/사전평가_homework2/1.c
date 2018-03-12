#include<stdio.h>

int main(void)
{
	char i=0;
	
	printf("대소문자를 변경해 줍니다\n");
	scanf("%c",&i);


	if(i>='a' && i<='z')
		printf("%c -> %c\n",i,i-32);
	else if(i>='A' && i<='Z')
		printf("%c -> %c\n",i,i+32);
	else
		printf("알파벳이 아닙니다!\n");


	return 0;
}



