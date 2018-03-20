#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	char *str = "WTF, Where is my Important Pointer?";

	int i,len,res=0;
	len= strlen(str);
	printf("글자 길이 : %d\n", len);
	for(i=0;i<len;i++){
		if(str[i] >= 'a'){
			res++;
			printf("%c", str[i]);
		}
	}
	printf("\nWTF, Where is my Importatn Pointer?\n");
	printf("소문자의 개 수: %d\n", res);

	return 0;
}
