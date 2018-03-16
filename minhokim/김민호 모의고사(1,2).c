/*
#include<stdio.h>

float func(int a,float b)
{
    float res=(float)a*b;

    return res;
}

int main()
{
    int a;
    float b;
    printf("정수 , 실수 하나씩 입력하세요 : ");
    scanf("%d %f",&a,&b);
    printf("두수의 곱은 %f",func(a,b));
    return 0;
}

*/
/*

#include<stdio.h>

int func1(int a,int b)
{
    int i=0;
    int sum=0;
    for(i=a;i<b;i++){

	if(i%2==0)
	    sum=sum+i;
    }	

    return sum;
}

int func2(int a,int b)
{
    int i=0;
    int sum1=0;
    for(i=a;i<b;i++){
	if(i%2!=0)
	    sum1=sum1+i;
    }
    return sum1;
}

int main()
{

    int a=1;
    int b=1000;
    printf("짝수의 합은 %d\n",func1(a,b));
    printf("홀수의 합은 %d\n",func2(a,b));
    printf("짝수합 나누기 홀수의 합 정수형으로 : %d\n",(int)func2(a,b)/func1(a,b));
    return 0;
}
*/
/*
#include<stdio.h>

void func(int a,int b)
{
    printf("%d",num1<<num2);
    printf("%d",num1>>num2);
    printf("%d",num1&num2);
    printf("%d",num1|num2);
    printf("%d",num1^num2);
    
}


int main()
{
    int num1=7;
    int num2=4;
    func(num1,num2);
    return 0;
}
*/
/*
#include<stdio.h>

void gugu(int a,int b)
{
    for(a=2;a<10;a++)
    {
	printf("%d단\n",a);
	for(b=1;b<10;b++)
	{
	    printf("%d * %d = %d",a,b,a*b);
	    printf("\n");
	}
    }
    printf("\n");
}
int main()
{
    int a,b;
    gugu(a,b);
}
*/
/*

#include<stdio.h>
int main()
{
    int i;
    char str[100];
    printf("문자열을 입력하세요 : ");
    scanf("%s",str);
    printf("홀수의 문자는 : ");
    for(i=0;i<100;i++)
    {
	if(str[i]=='\0')
	    break;
	if(i%2!=0)
	    printf("%c",str[i]);
    }
    printf("\n");
    return 0;
}

*/
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i;
    int sum;
    int bae[20]={0};
    
    for(i = 0; i < 20; i++)
	bae[i] = rand()%101;

    for(i=0;i<20;i++)
    {
	if(bae[i]%2==0)
	{
	   sum=sum+bae[i];
	}
	
    }
    printf("%d",sum);
    printf("\n");
    return 0;
}
*/
/*

#include<stdio.h>
#include<stdlib.h>

void func1(int *bae,int i,int *sum)
{
    for(i=0;i<20;i++){
    	bae[i]=rand()%101;
    
    }
    for(i=0;i<20;i++)
    {
	if(bae[i]%2==0)
	{
	    *sum=*sum+bae[i];
	}
    }
}

void func2(int *bae,int i,int *sum1)
{
    for(i=0;i<20;i++)
    {
	if(bae[i]%2!=0)
	{
	    *sum1=*sum1+bae[i];
	}
    }
}


int main()
{  
    int i;
    int sum=0;
    int bae[20]={0};
    func1(bae,i,&sum);
    printf("짝수의 합은 : %d",sum);
    printf("\n");
    int sum1=0;
    func2(bae,i,&sum1);
    printf("홀수의 합은 : %d",sum1);
    printf("\n");
    printf("짝수,홀수의 곱은 : %d",sum*sum1);
    printf("\n");
    return 0;

}

*/

/*

#include<stdio.h>
#include<stdlib.h>

void func1(char *a)
{
    int i;
    for(i=0;i<20;i++)
    {
	if(a[i]>=65 && a[i]<=90)
	{
	    a[i]=a[i]+32;

	}
    }
       printf("%s->",a);
    
}

void func2(char *a)
{
    int i;
    for(i=0;i<20;i++)
    {
	if(a[i]>=97 && a[i]<=122)
	{
	   a[i]=a[i]-32;
	}
    }
    printf("%s-> ",a);
}


int main()
{
    char a[20];
    printf("소문자or 대문자로 알파벳을 입력하세요\n");
    scanf("%s",a);
    func1(a);
    func2(a);
    return 0;
}
*/

/*
#include<stdio.h>

void swapnum(int *num1,int *num2)
{
    int abc;
    printf("swap 전의 값은 : %d %d",*num1,*num2);
    printf("\n");
    abc=*num1;//10
    *num1=*num2;//100
    *num2=abc;//10
    printf("swap 후의 값은 : %d %d",*num1,*num2);
    printf("\n");
}

int main()
{
    int num1=10;
    int num2=100;
    
    swapnum(&num1,&num2);
    return 0;
}

*/
/*

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct person{
    char name[10];
    int age;
    char address[30];
};

int main()
{
    struct person p1;

    strcpy(p1.name,"홍길동");
    p1.age=30;
    strcpy(p1.address,"서울시 용산구 한남동");

    printf("이름: %s\n",p1.name);
    printf("나이: %d\n",p1.age);
    printf("주소: %s\n",p1.address);
    
    printf("\n");
    printf("\n");

    struct person *p2=malloc(sizeof(struct person));
    strcpy(p2->name,"김길동");
    p2->age=22;
    strcpy(p2->address,"울산울산");
    
    printf("이름: %s\n",p2->name);
    printf("나이: %d\n",p2->age);
    printf("주소: %s\n",p2->address);

    free(p2);


    return 0;
}

*/
/*

#include<stdio.h>
#include<string.h>

struct person{
    char name[20];
    int age;
    char address[40];
};


void changeperson(struct person *p1)
{
    strcpy(p1->name,"김김민민호호");
    p1->age=36;
    strcpy(p1->address,"서울시 서초구 서초동");
}

int main()
{
    struct person p1;
    strcpy(p1.name,"김민호");
    p1.age=28;
    strcpy(p1.address,"서울시 중랑구 상봉동");

    printf("--------------------------------------------------------------변경전 신상-------------------------------------------------------\n");
    printf("이름:%s\n",p1.name);
    printf("나이:%d\n",p1.age);
    printf("주소:%s\n",p1.address);
    printf("\n\n\n\n\n");

    changeperson(&p1);
    printf("--------------------------------------------------------------변경후 신상------------------------------------------------------\n");
    printf("이름:%s\n",p1.name);
    printf("나이:%d\n",p1.age);
    printf("주소:%s\n",p1.address);
    printf("\n\n\n\n\n");
    return 0;
}
*/
/*

#include<stdio.h>
int sum(int ******n6)
{
    printf("%d\n",******n6);
}

int main()
{
    int num=7;
    int *n1=&num;
    int **n2=&n1;
    int ***n3=&n2;
    int ****n4=&n3;
    int *****n5=&n4;
    int ******n6=&n5;
    sum(n6);

    return 0;
}

*/

#include<stdio.h>

int fib(int final_val)
{
    if(final_val==1 || final_val==2)
	    
	return 1;
    else

	return fib(final_val-1)+fib(final_val-2);
}



int main()
{
    int result;
    int final_val;
    printf("피보나치 수열의 항의 개수를 입력하시오 : ");
    scanf("%d",&final_val);
    result=fib(final_val);
    printf("%d번째 항의 수는=%d\n",final_val,result);
    return 0;
}



























