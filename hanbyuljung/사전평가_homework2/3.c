#include<stdio.h>

int main(void)
{
	int x=0,t=0,len=0;
	int i[]={0};

	printf("임의의 수 x를 입력하시오\n");
	scanf("%d",&x);

	len = x/4096;

	if(x<4096)
		printf("%d\n", x);
	else{
		while(t <= len)
		{
			if(t==0)
				printf("%d ",x%4096);
			else
				printf("%d ",4096);
			t++;

		}
		printf("\n");

	}


}
