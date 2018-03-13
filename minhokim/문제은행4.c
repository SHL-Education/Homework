/*

//1번
#include<stdio.h>
void func(float *hap,int *gobb)
{
    int num1;
    float num2;
    printf("정수와 실수를 하나씩 입력하세요 : ");
    scanf("%d %f",&num1,&num2);

    *hap=(float)(num1+num2);
    *gobb=(int)(num1*num2);
    
       
}



int main()
{
    
    float hap=0;
    int gobb=0;
    
   
    func(&hap,&gobb);
    
    printf("합은 %f ",hap);
    printf("\n");
    printf("곱은 %d \n",gobb);
    return 0;
}

*/

//2번
/*
#include<stdio.h>
int main()
{

    int i;
    int num=2004016;
    char *num1=&num;

    for(i=0;i<4;i++)
            printf("%d ",num1[i]);
    return 0;
}

*/

