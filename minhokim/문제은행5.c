#include<stdio.h>









int main()
{


    int a=0;
    int x;
    printf("x의 값을 입력 : ");
    scanf("%d",&x);
    a=((3*x)+4);
    func(a);
    printf("%d\n",a*a);
    return 0;
}
