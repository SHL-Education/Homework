#include <stdio.h>


typedef int INT;
typedef int* PINT;

int main(void)
{

	INT num =3;
	PINT ptr = &num;

	printf("num = %d\n",*ptr);

	return 0;

}
