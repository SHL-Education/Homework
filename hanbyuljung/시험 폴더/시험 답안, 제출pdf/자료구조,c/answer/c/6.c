#include <stdio.h>
#include <string.h>

int where_is_it(char *text, char *find)
{
	int i;

	for(i = 0; text[i]; i++)
		if(!(strncmp(&text[i], find, strlen(find))))
			return i;
}

int main(void)
{
	int idx;
	char text[100] = "TI Cortex-R5F Safety MCU is very good to Real-Time System.";

	idx = where_is_it(text, "Safety MCU");
	printf("idx = %d\n", idx);

	return 0;
}
