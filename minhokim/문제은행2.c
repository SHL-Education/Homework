/*
   //1번
#include<stdio.h>

void borw(int day,int pri)
{
    if(day>=3)
    {
	printf("%d일대여 가격은 %lf 입니다. \n",day,(day*pri)*0.8);
    }
    
    else if(day>=2)
    {
	printf("%d일대여 가격은 %d 입니다.\n",day,day*pri);
    }


}

int main()
{
    int day;
    int pri=37500;
    printf("1일장비 임대료 37,500원 3일이상 대여시 20%%할인\n\n");
    printf("대여할 기간을 입력: ");
    scanf("%d",&day);
    borw(day,pri);
    return 0;
}

*/
//2번
/*
#include<stdio.h>
void cal(int a,int b)
{
    for(b=1;b<=a;b++)
    {
	if(a%b==0)
	    printf("%2d\n",b);
    }
}

int main()
{
    int a,b,c;
    printf("약수를 구할 정수 입력: ");
    scanf("%d",&a);
    cal(a,b);
    return 0;
}
*/
//3번
/*
#include<stdio.h>

int cal(int a,int b,int c)
{
    int i;
    int sum=0;
    for(i=a;i<=b;i++)
    {
	if(i%3==0)
	sum=sum+i;

    }
    return sum;
}

int main()
{

    printf("1~1000사이 3의 배수의 합은: %d\n",cal(1,1000,3));
    return 0;
}
*/
//4번
/*
#include<stdio.h>

int cal(int a,int b)
{
    int num;
    int sum=0;
    for(num=a;num<=b;num++)
    
	if(((num%4==1))&&((num%6==1)))
	{
	    sum=sum+num;
	}
    
    return sum;
}
    
int main()
{
    printf("1~1000사이 4,6으로 나눠도 나머지가 1인 수의 합은 : %d\n",cal(1,1000));
    return 0;
}

*/

//10번
/*
#include<stdio.h>

void cal(int a)
{   
    int b;
    for(b=1;b<10;b++)
	printf("%dx%d=%d\n",a,b,a*b);

}


int main()
{   
    int a;
    printf("원하는 구구단 입력 : ");
    scanf("%d",&a);
    cal(a);
    return 0;
}

*/

//10번 변형 
/*  
#include<stdio.h>

void cal()
{
    int a,b;
    for(a=1;a<10;a++)
    {
	printf("%d단\n",a);
	for(b=1;b<10;b++)
	    printf("%dx%d=%d\t",a,b,a*b);

	if(a%3 == 0)
	    printf("\n");
    }
}

int main()
    
    {
    
       
      	printf("1단~19단까지의 구구단\n");
	cal();
	return 0;
    }
*/

//5번
#include<stdio.h>
int cal(int a)
{
    return a*7;
}


int main()
{
 
 int a;
printf("원하는 숫자 입력 : ");
printf("\n");
scanf("%d",&a);
printf("%dx7=%d\n",a,cal(a));

return 0;
}





















