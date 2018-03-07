/*
#include<stdio.h>

float cal(float a,int b)
{
    return a*b;
}





int main()
{
    float a;
    int b;
    printf("실수형  숫자 1개 , 정수형 숫자 1개를 입력하세요 : \n");
    scanf("%f %d",&a,&b);
    cal(a,b);
    printf("결과는 %f\n",cal(a,b));
    return 0;
   	
}

*/

//2번
/*
#include<stdio.h>
int cal(int num1,int num2)
{   
    int res;
    res=num1<<num2;
    return res;
}



int main()
{
    int num1,num2;
    printf("정수형 숫자 2개를 입력하세욖: \n");
    scanf("%d %d",&num1,&num2);
    cal(num1,num2);
    printf("결과 값은 %d\n",cal(num1,num2));
    return 0;
}
*/
//3번 번형
/*
#include<stdio.h>
void cal(float a)
{
    printf("몫:%d\n",(int)a/1);
    
}

void namuji(float a)
{ 
      printf("나머지:%f\n",a - (int)a/1);
}

int main()
{
    float a;
    printf("실수형 숫자 1개를 입력하세요 : \n");
    scanf("%f",&a);
    cal(a);
    namuji(a);
    return 0;
}
*/

//3번
/*
#include<stdio.h>
void cal1(float a)
{
   int jung=(int)a;
    printf("정수의 값은: %d\n",jung);
}

void cal2(float a)
{
    int b=(int)a;
    printf("소수점의 값은: %f\n",a-b);
}

int main()
 {
    float a;
    int b;
    printf("실수형 숫자 1개를 입력하세요 :\n");
    scanf("%f",&a);
    cal1(a);
    cal2(a);
    return 0;
 }
 */

//4번
//shortcut에 의한  - 논리 연산자 && 와 || 
/*
#include<stdio.h>
int main()
{
    printf("%d\n",1&&1);
    printf("%d\n",1&&0);
    printf("%d\n",0&&1);//앞인자가 거짓이니 인자1은 살피지 않는다.
    printf("%d\n",0&&0);//앞인자가 거짓이니 인자0은 살피지 않는다.
    
    printf("%d\n",1||1);
    printf("%d\n",1||0);
    printf("%d\n",0||1);//앞인자가 참이 아니니 인자1은 살피지 않음.
    printf("%d\n",0||0);//앞인자가 참이 아니니 인자0도 살피지 않는다.
    return 0;
}

*/

