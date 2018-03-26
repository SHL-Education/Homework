#include <stdio.h>

int check_lower(char *str)
{
	int i = 0, cnt = 0;

	for(; str[i]; i++)
		if(str[i] >= 97 && str[i] < 123)	// 아스키코드표의 십진수로 97~122에 해당하는 문자의 갯수를 cnt에 저장함.
			cnt++;

	return cnt;
}

int main(void)
{
	int cnt;
	char *str = "WTF, Where is my Important Pointer ?";
	cnt = check_lower(str);
	printf("cnt = %d\n", cnt);
	return 0;
}

/*
문자열 중에서 소문자만 찾아냄.
아스키코드표에서 소문자에 대한 십진수는 97~122 이다.
*/
