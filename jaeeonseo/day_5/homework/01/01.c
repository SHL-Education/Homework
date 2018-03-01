#include <stdio.h>

int main(void)
{
	char strArray[100] ={0};
	int i;

	printf("문자열을 입력하세요: ");
	scanf("%s", strArray);

	for(i=0; i < 100; i++)
	{
		if(!(i%2))
		{

			printf("%c ", strArray[i]);
			
			if(strArray[i] == '\0')
			{
				break;
			}
		}
	}

	printf("\n");

	return 0;
}
