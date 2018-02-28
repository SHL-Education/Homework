#include <stdio.h>

int main(void)
{
	int num = 2004016;
	int i;
	char *oneChar=NULL;

	oneChar = &num;
	
	printf("현재 숫자: %d\n", num);
	
	for(i=0; i< 4; i++)
	{
		printf("%d byte: %c\n",i, *oneChar);
		oneChar++;
	}

	return 0;
}
		
	
