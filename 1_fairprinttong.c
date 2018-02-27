#include<stdio.h>
int main(void)
{	
	int i;
	char abc[] = {'a','b','c','d','e','f','g'};
	for(i = 0 ; i < 7; i++)
	{
		if(abc[i] %2 ==0){
		printf("%d",abc[i]);
		}
	}
	return 0;
}
