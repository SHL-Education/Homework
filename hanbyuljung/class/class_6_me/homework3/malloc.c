#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char *str_ptr=(char*)malloc(sizeof(char)*20);

	printf("Input String:");
	scanf("%s", str_ptr);

	if(str_ptr != NULL)
		printf("string = %s\n",str_ptr);

	free(str_ptr);
	
	return 0;

}

