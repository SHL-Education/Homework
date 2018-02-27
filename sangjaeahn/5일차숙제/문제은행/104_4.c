#include <stdio.h>

int main(void)
{
	int num1=1, num2=2, num3=3;
	int *num1_p=&num1, *num2_p=&num2, *num3_p=&num3;
	int *temp;
	int i;
		
	while(1)
	{
		printf("%d %d %d\n",*num1_p,*num2_p,*num3_p);
	
		temp = num1_p;
		num1_p = num2_p;
		num2_p = num3_p;
		num3_p = temp;
		
		for(i=0;i<500000000;i++);
	}

	return 0;
}
