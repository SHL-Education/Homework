#include <stdio.h>

void print_seven_series(int num)
{
	int i = 1;

	for(i=1;i<num+1;i++)
	{
		if(i < num)
		{
			printf("%d\t", i * 7);
		}
		else
		{
			printf("%d\n", i * 7);
		}
	}
}

int main(void)
{
	int num;
	printf("보고싶은 7의 배수의 n번째 항은?");
	scanf("%d", &num);
	print_seven_series(num);
	return 0;
}
