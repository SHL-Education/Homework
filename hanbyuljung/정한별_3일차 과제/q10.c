#include<stdio.h>


int mul()
{
        int  i=1,j=1;
        while(i<10)
        {
                printf("\n <%d 단>\n",i);
                j=1;
                while(j<10){

                        printf("%d * %d = %d\n",i,j,i*j);
                        j++;
                }
                i++;
        }

}

int main(void)
{

        printf("구구단\n");
        mul();
        return 0;

}

