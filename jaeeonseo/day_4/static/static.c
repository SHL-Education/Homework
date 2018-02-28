
#include <stdio.h>

void count_static_value(void)
{
	static int count = 1;			//함수 진입시 최초에 1번만 count=1 등록
	printf("count = %d\n", count);
	count++;
}

int main(void)
{
	int i;

	for(i=0; i < 7; i++)
		count_static_value();
}
