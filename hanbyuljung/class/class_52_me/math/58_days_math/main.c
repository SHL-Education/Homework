#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define delta_x 0.001
#define E 2.7182818284590452353602874

void original_solve(double *A)
{
    double x = delta_x;
    double ii = x*-5000;
    printf("first num = %lf \n", ii);
    for(int i=1;i <= 10001;i++){
        A[i-1] = 3*pow(E,-pow(-5.000+x*(double)(i-1),2.0));
        printf("%11.6lf", A[i-1]);
        if(i%10 == 0)
            printf("\n\r");
    }
}

void second_solve(double *B)
{
    double x = delta_x;
    double ii = x*-5000;
    printf("first num = %lf \n", ii);
    for(int i=1;i < 5000;i++){
        B[i] = (-2*x*(x*(double)(i-1))+1)*B[i-1];
        printf("%11.6lf", B[i-1]);
        if(i%10 == 0)
            printf("\n\r");
    }
}

void percentage(double *A, double *B)
{
    for(int i=0; i<4999; i++)
    {
        printf("%11.6lf%%", A[i+5000]/B[i+1]*100);
        if(i%10 == 0)
            printf("\n\r");
    }
}

int main(void)
{
    printf("original solve is y = 3e^(-x^2).\n");
    printf("y' = -2xy , y(0) = 3. \n");

    printf("start 미방. \n");

    double first_matrix[10001] = {0};
    double second_matrix[10001] = {0};

    second_matrix[0]=0;
    second_matrix[0] = 3.0;

    original_solve(first_matrix);
    printf("\n0 일 때 : %.05lf \n", first_matrix[5000]);
    printf("\n");

    second_solve(second_matrix);
    printf("\n0 일 때 : %.05lf \n", second_matrix[0]);

    percentage(first_matrix, second_matrix);

    return 0;
}

