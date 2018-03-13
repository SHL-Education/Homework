//1번
/*
#include<stdio.h>
int main()
{
    char str[10]="minking12";
printf("%c\n",str[0]);
	printf("%c\n",str[2]);
	    printf("%c\n",str[4]);
		printf("%c\n",str[8]);
		    printf("%c\n",str[10]);
     return 0;
} 
*/
//1번 변형
/*
#include<stdio.h>

int main()
{
    int i;
    char str[50];
    printf("문자열을 입력하세요: ");
    scanf("%s",str);
    printf("짝수의 문자는 ");
      
    for(i = 0; i < 50; i++)
    {
	if(str[i]=='\0')
	    break;
	if(!(i%2))
	    printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}

*/

//3번
/*

#include<stdio.h>
int main()
{
    int bae[]={3,77,10,7,4,9,1,8,21,33};
    for(int i=sizeof(bae)/sizeof(int)-1;i>=0;i--)
    {
	printf("%d\n",bae[i]);
    }

return 0;
}

*/

//4번
/*

#include<stdio.h>

//배열의 홀수요소값
void funcstra(int *baee)
{

    printf("배열의 홀수는 : ");


    for(int i=0;i<10;i++)
    {

	if(baee[i]%2!=0)
	{
	  
	   printf("%d ",baee[i]);
	}
    }
    
    printf("\n");
}

//배열의 짝수요소값	
void funcdou(int *baee)
{
    printf("배열의 짝수는 : ");

    for(int i=0;i<10;i++)
    {
	if(baee[i]%2==0)
	{
	    printf("%d ",baee[i]);
	}
    }
    printf("\n");
}

//홀수 합
void funcsum(int *baee)
{
    int sum = 0;

    printf("배열 홀수 값의 합은 : ");
    for(int i=0;i<10;i++)
    {
	if(baee[i]%2!=0)
	{
	    sum=sum+baee[i];
	}
    }
    printf("%d",sum);
    printf("\n");
}
	    
//짝수 합
void funcsum1(int *baee)
{
    int sum = 0;
    printf("배열 짝수 값의 합은 : ");
    for(int i=0;i<10;i++)
    {
	if(baee[i]%2==0)
	{
	    sum=sum+baee[i];
	}
    }
    printf("%d",sum);
    printf("\n");
}

void funcsum2(int *baee)
{
    int sum = 0,sum1 = 0,sum2 = 0;
    
    
    for(int i=0;i<10;i++)
    {
	if(baee[i]%2==0)
	{
	    sum=sum+baee[i];
	}
    }

    for(int i=0;i<10;i++)
    {
	if(baee[i]%2!=0)
	{
	    sum1=sum1+baee[i];
	}
    }
    
    sum2=sum*sum1;

    printf("짝수 홀수 요소값의 곱 은 : %d",sum2);
    printf("\n");
}

int main()
{
  int baee[]={3,77,10,7,4,9,1,8,21,33};

  funcstra(baee);//배열의 홀수
  funcdou(baee);//배열의 짝수
  funcsum(baee);//홀수 합
  funcsum1(baee);//짝수 합
  funcsum2(baee);//홀수합x짝수합
  return 0;  
   
   
}

*/



