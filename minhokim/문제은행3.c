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
#include<stdio.h>
int main()
{

    int a[]={3,77,10,7,4,9,1,8,21,33};
   
    printf("%d",a);
    return 0;
}

