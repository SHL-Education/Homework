#include <stdio.h>

int main(void)
{
	int x;
	
	scanf("%d",&x);
	
	printf("%d\n",x&~((2^27)-1));
	
	return 0;
}
