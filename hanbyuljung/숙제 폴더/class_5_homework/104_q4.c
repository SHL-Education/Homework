#include <stdio.h>

int main(void)
{
		int num1 = 3, num2 =7, num3=5;
		int *temp = NULL;
		int *num1_p = &num1;
		int *num2_p = &num2;
		int *num3_p = &num3;

		int **num_p_p= &num1_p;


		printf("num1_p= %d \n", *num1_p);
		printf("num2_p= %d \n", *num2_p);
		printf("num3_p= %d \n", *num3_p);

		printf("\n");

		for(;;){
				temp = num1_p;
				num1_p =num2_p;
				num2_p = num3_p;
				num3_p = temp;

				printf("num1_p= %d \n", *num1_p);
				printf("num2_p= %d \n", *num2_p);
				printf("num3_p= %d \n", *num3_p);

		printf("\n");
		}

		return 0;

}
