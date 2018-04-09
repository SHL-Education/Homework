#include<stdio.h>

int glob_val = 7;

void multi(void)
{

	glob_val*=3;
}

void add(void)
{
	glob_val+=3;
}

int main(void)
{

	add();
	multi();
	printf("glob_val = %d \n",glob_val);
	return 0;
}
