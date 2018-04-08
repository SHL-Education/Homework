#include<stdio.h>


int main(void)
{
	int number=0;
	while(1)
	{
		number++;
		
		if(number==5)
			continue;

		printf("%d\n",number);
		if(number==10)
			break;
	}
	return 0;

}
