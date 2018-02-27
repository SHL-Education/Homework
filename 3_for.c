#include <stdio.h>

// synthesis: first - start, second - end, three - times
int syn(int start, int end, int times)
{
	int res = 0, i = start;

	for(i = start;i  < end + 1;i++)
	{
		if(!(i % 3))
		{
			res += i;
		}
		
	}

	return res;
}

int main(void)
{
	printf("tot series sum = %d\n", syn(1, 1000, 3));
	return 0;
}




