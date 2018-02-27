#include<stdio.h>

int main(void)
{
        int global_area=1;

        {
                int local_area1 =2;
                printf("globla_area=%d \n", global_area);
                printf("laca_area=%d\n", local_area1);
        }
        {
                int local_area2 =3;
                printf("globla_area=%d \n", global_area);
                printf("laca_area2=%d\n", local_area2);
        }


        printf("globla_area=%d \n", global_area);



        return 0;

}

