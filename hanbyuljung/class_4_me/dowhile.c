#include<stdio.h>


int main(void)
{
	int number=0;
	do
	{
		number++;
		
		if(number==5)
			continue;

		printf("%d\n",number);

	}while(number<10);
	return 0;

}
