#include <stdio.h>


int syn(int start, int end, int times)
{
	int res=0, i = start;
	while(i<end +1)
	{
		if(!(i%3))
		{
		 res +=i;
		}
		i++;
	}

	return res;

}



int main(void)
{

	printf("tot series sum = %d\n", syn(1, 1000,3));
	return 0;

}
