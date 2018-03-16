#include <stdio.h>

int main(void)
{
	char *str = "WTF, Where is my Pointer ? Where is it?";
	int i=0;
	int cnt=0;	

	while(*(str+i))
	{
		if(*(str+i)>=97 && *(str+i)<=122)
		{
			cnt++;
		}
		i++;
	}
	
	printf("소문자 갯수는 %d 입니다.\n", cnt);
	return 0;
}
