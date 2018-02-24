#include<stdio.h>

int lental_fee(int a,int b)
{
        if(b>=3)
                return a*b*4/5;
        else
                return a*b;
}

int main(void)
{
        int lental_val = 37500;
        int days = 7;

        printf("일주일간 이용할 경우 임대요금은? %d \n",lental_fee(lental_val,days));

return 0;

}

