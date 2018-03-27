#include <stdio.h>

int main(void)
{
	int i;
	execlp("ps", "ps","-e","-f",0);
	printf("after\n");


	scanf("%d",&i);
	printf("%d\n",i);

	return 0;
}
