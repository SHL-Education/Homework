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
/*
float은 단정밀도 부동소수점
float num1=0.1f(변수선언)

double은 배정밀도 부동소수점(좀 더 긴 자릿수의 소수점을 표현할수 있음)
double num2=3867.215820(변수선언)  뒤에 알파벳 ? 붙이지 않음.




   */


//5번
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

//10번
/*

#include<stdio.h>
int main()
{
    int a=2;
    int b=4;
    int c=8;
    printf("%d\n",a&b);//&연산자는 두 비트가 모두1일때 1 하나라도 0이면0
    printf("%d\n",a|b);//|연산자는 비트가 하나라도 1이면1 두개가 0이여야0
    printf("%d\n",a^b);//두비트가 모두 다를때가 1 비트가 다 같으면0
    printf("%d\n",~c); //0이면1,1이면0으로 반전

    return 0;
}

*/

//11번
/*
   10진수 33을 2진수로 바꾸면
   0010/0001
여기에 ~ (not)연산을하면
   1101/1110

*/

//13번
/*
#include<stdio.h>

int doit(int a,int b)
{
    
  
    return a%b;
}

int letsgo(int a,int b)
{

    return a+b;
}

int main()
{

int a,b;
printf("정수형 숫자 2개 입력 : \n");
scanf("%d %d",&a,&b);
int ee,eee;
ee=doit(a,b);
eee=letsgo(a,b);

printf("%%의 값은 %d\n",ee);
printf("+의 값은%d\n",eee);
printf("두 함수의 곱의 값은%d\n",ee*eee);
return 0;

}
*/
//14번
/*
#include<stdio.h>


void func(int a,int b)
{
    int res;
    if(a>b)
    {
        res=(a>b)?a:b;
        printf("%d 이 더 크다\n",res);
    }

    else if(a==b)
    {
	res=(a==b)?a:b;
	printf("%d 과 %d 값이 같다\n",res,b);
    }
    
    else if(a<b)
    {
	res=(a<b)?b:a;
	printf("%d 값이 %d 보다 크다\n",res,b);
    }

	
   
}

int main()
{
    int a,b;
    printf("정수형 숫자 2개를 입력하세요 : \n");
    scanf("%d %d",&a,&b);
    func(a,b);
    return 0;
}
*/

//15번
/*
#include<stdio.h>

int cal(int a,float b)
{
    return (int)a+b;
}

int main()
{
    int a=3;
    float b=7.7;
    printf("%d\n",cal(a,b));

    return 0;
}
*/
//7번
/*
함수정의를 메인아래 적었을경우 왜 에러가 나는지 
c언어 컴파일러는 위에서부터 아래로 소스코드를 해석하는데 메인 함수 부분에서는 함수에 대한 정보가 없기때문에 에러가 난다.
*/

//9번
/*
오버플로우는 자료형의 크기가 저장할수있는 최대크기를 초가했기 때문에 발생한다.
char 형의 경우의 최댓값은 127인데 128이상의 크기를 표현하게 되면오히려 맨 아래로내려간다. -128
언더플로우도 표현할수있는 최소값에서 더 아래로 내려갈경우 반대로 맨 위로 올라감
127로 ...
*/
//
/*
   변수란 숫자,문자와 같은 값들을 저장하는 공간
  게임상에서 캐릭터의 능력치를 제대로 저장하지 않으면 오류가 나듯 변수에 값들을 저장한다.
  */
//스택 힙 ...
/*
스택: 프로그램이 자동으로 사용하는 임시메모리 영역 
지역함수,매게변수,리턴값이 할당되는 영역
임시적으로 저장되었다가 사라지는 영역

힙: 동적으로 메모리를 할당한곳

데이터:전역변수,지역변수,초기값이 없는 변수는 data영역에
초기값이 없는 경우 bss영역에 할당된다

코드(ㅅ텍스트):프로그램이 위치한 부분으로 코드가 메모리에 로드되면 이 부분에서 실행

*/
*/
