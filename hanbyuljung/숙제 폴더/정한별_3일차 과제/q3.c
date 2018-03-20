#include<stdio.h>

int cal()
{
	int num=1;
	int sum=0;
	while(num<=1000){
		if(!(num%3)){
			printf("debug용 %d\t",num);
			sum+=num;	
		}
		num++;
	}
	return sum;
}

int main(void)
{

	printf("\n 1 ~ 1000 까지의 3의 배수의 합은= %d\n",cal());
	return 0;

}
