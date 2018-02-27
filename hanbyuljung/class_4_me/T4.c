#include<stdio.h>

                int local_area2 =3;
                int local_area1 =2;
int main(void)
{
        int global_area=1;

        {
                printf("globla_area=%d \n", global_area);
                printf("laca_area=%d\n", local_area1);
        }
        {
                printf("globla_area=%d \n", global_area);
                printf("laca_area2=%d\n", local_area2);
        }

	printf("global_area2= %d\n",local_area2);
	printf("global_area1= %d\n",local_area1);
        printf("globla_area=%d \n", global_area);

        return 0;
}

