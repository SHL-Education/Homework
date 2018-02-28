#include <stdio.h>

int main(void)
{
	int a=1; 
	int b=2;
	int c=3;
	int *ptr[3]= {&a, &b, &c};
	int *temp=NULL;
	int i;

	for( ; ; )
	{
		printf("a: %d, b:%d, c:%d\n", *ptr[0], *ptr[1], *ptr[2]);
		
		temp = ptr[i%3];
		ptr[i%3] = ptr[(i+1)%3];
		ptr[(i+1)%3] = ptr[(i+2)%3];
		ptr[(i+2)%3] = temp;
		
		i++;
	}

	return 0;
}
