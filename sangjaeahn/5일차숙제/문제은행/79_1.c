#include <stdio.h>

int main(void)
{
	char string[50] = {0,};
	int i;

	printf("문자열을 입력하시오.\n");
	scanf("%s",string);
	
	for(i=0;string[i] != 0;i++)
	{
		if(i%2 == 0)
		{
			printf("%c",string[i]);
		}
	}	

	printf("\n");
	return 0;
}
