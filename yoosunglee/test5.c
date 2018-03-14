#include<stdio.h>
int main(void){
	
	char str1[33] = "Pointer is important!";
	char *str2 = "Pointer is important!";
	// 변수 str2가 가지고 있는 주소가 가르키는 곳은 배열,,

	printf("str1 = %s\n", str1);
	printf("str2 = %s\n", str2);
	
	return 0;
}
