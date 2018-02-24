#include<stdio.h>

int cal(int a)
{
	return 7*a;
}

int main(void)
{

	int num=0;
	printf("보고싶은 7의 배수의 n번째 항은?");
	scanf("%d",&num);

	printf("%d의 항은 %d \n",num,cal(num));

	return 0;

}
