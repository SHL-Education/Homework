#include <stdio.h>
#include <string.h>

void chg_order(char *str)
{
	int i, len = strlen(str);

	printf("len = %d\n", len);

	for(i = 0; i < len; i++)
		if((str[i] >= 97 && str[i] < 123) || (str[i] >= 65 && str[i] < 91))	// 대문자->소문자, 소문자->대문자로 바꾸어줌.
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

/*
어떤 문자를 0x20을 xor 시키면 소문자에서 대문자로, 대문자에서 소문자로 변경이 된다.
대문자와 소문자의 이진수는 5번째 비트만 다르고 나머지 비트는 모두 같다.
*/
