#include <stdio.h>

void arr_print(int num)
{

		if(!(num%2))
			printf("%d ",num);


}


int main(void)
{
		int i=0;
		int t=0;
		int a[t];

		printf("배열의 크기를 입력하시오\n");
		scanf("%d",&t);

		printf("배열에 들어가 요소를 %d개 입력하시요\n",t);

		for(i=0;i<t;i++)
		{
				scanf("%d",&a[i]);
		}
				
		for(i=0;i<t;i++)
				arr_print(a[i]);
		printf("\n");
					

		return 0;	
}

