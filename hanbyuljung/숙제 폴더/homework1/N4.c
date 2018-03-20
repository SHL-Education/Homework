#include <stdio.h>

int syn(int start, int end, int t1, int t2)
{
	int res=0, i = start;


	for(res=0;i++;i<end+1)
	{
		if(((i % t1) == 1) || ((i % t2) == 1))
		{
			res += i;
		}
	}

	return res;
}

int main(void)
{
	printf("tot series sum = %d\n", syn(1, 1000, 4, 6));
	return 0;
}




