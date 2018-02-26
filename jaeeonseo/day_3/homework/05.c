#include <stdio.h>

int retLastVal(int num)
{
	int i;
	int retVal; 

	for(i=1; i < num+1; i++)
	{

		retVal = 7*i;
	}

	return retVal;
}



int main(void)
{
	int nPnum;
	int nLastVal;
       

        printf("7의 배수의 항을 입력하세요:");
	scanf("%d", &nPnum);

	nLastVal = retLastVal(nPnum);
	printf("%d개의 7의 배수 중 마지막 항은 %d\n",nPnum,  nLastVal);

	return 0;
}
	
