#include <stdio.h>

int check_lower(char *str)
{
	int i = 0, cnt = 0;

	for(; str[i]; i++)
		if(str[i] >= 97 && str[i] < 123)
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
