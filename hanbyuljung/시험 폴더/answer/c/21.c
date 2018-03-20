#include <stdio.h>
#include <string.h>

void chg_order(char *str)
{
	int i, len = strlen(str);

	printf("len = %d\n", len);

	for(i = 0; i < len; i++)
		if((str[i] >= 97 && str[i] < 123) || (str[i] >= 65 && str[i] < 91))
			str[i] ^= 0x20;
}

int main(void)
{
	char test[10] = "Who am I";
	printf("test = %s\n", test);
	chg_order(test);
	printf("test = %s\n", test);

	return 0;
}
