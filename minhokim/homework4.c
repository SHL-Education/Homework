//4일차 과제 인데 양식 만들기가 ... 다 따라잡은 후에 양식 해서 올리겠습니당...




/*  1번 (2)

#include<stdio.h>


int rent_equip(int day, double money)
{
    int i;
    int sum=0;
    double rate=1.0;
    if(day>=3)
	rate=0.8;

    for(i=0;i<=7;i++)
	sum=sum+money*rate;

    return sum;
}

int main()
{
    printf("money=%d\n", rent_equip(7,37500));
    
    return 0;
}

*/


///////////////////////////////////////////////////////////////////////////////////////////////////////
/* 3번 (2)

#include<stdio.h>

int sum(int s,int e, int t)
{
    int i=1;
    int sum=0;
    for(i=s;i<=e;i++)
	if(!(i%3))
	    sum=sum+i;
    return sum;
}

int main()
{
    printf("1~1000까지 3의 배수의 합은 : %d",sum(1,1000,3));
    return 0;
}

*/
////////////////////////////////////////////////////////////////////////////////////////////////////

/* 4번(2)

#include<stdio.h>

int sum(int s, int e, int t1, int t2)
{
    int i=1;
    int sum=0;

    for(i=s;i<=e;i++)
	if(((i%4)==1)||((i%6)==1))
	    sum=sum+i;

    return sum;
}

int main()
{
    printf("1~1000사이에서 4,6으로 나눠도 나머지가 1인수의 합을 구하라 : %d",sum(1,1000,4,6));
    return 0;
}

*/

////////////////////////////////////////////////////////////////////////////////////////////////////

/* 5번(2)

#include<stdio.h>

void print_seven(int num)
{
    printf("res=%d\n",num*7);
}

int main()
{
    int num;
    scanf("%d",&num);

    print_seven(num);

    return 0;
}

*/

////////////////////////////////////////////////////////////////////////////////////////////////////

/*  10번(2)

#include<stdio.h>
    int main()
{

    int a,b;

	printf("2~9단 숫자 입력 : ");
	scanf("%d",&a);
	for(b=1;b<10;b++)
	{
	    printf("%d*%d=%d\n",a,b,a*b);
	}

	return 0;
}

*/
