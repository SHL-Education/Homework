#include<stdio.h>

void cal(int *a)
{
		int i;
		for(i=0;i<7;i++){
				a[i]=a[i]*104*3/100;
				printf("%d 번 통장의 금액: %d\n",i+1,a[i]);
		}
}


int main(void)
{
		int i =0;
		int a[7]={0};

		for(i=0;i<7;i++){
				printf("통장%d의 500만원 이하로 입금할 돈을 넣으시오\n",i);
				printf("단위는 백만원 단위입니다.\n");
				scanf("%d",&a[i]);
		}
		cal(a);
		return 0;

}

