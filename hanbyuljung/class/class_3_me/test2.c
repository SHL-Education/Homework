#include<stdio.h>

int main(void)
{
	int chr1 = 'A', chr2='B',chr3='C';

	printf("A의 해당하는 수는 = %d\n" , chr1);
	printf("소문자는 = %c\n" , chr1^32);
	printf("A-B +C= %c\n" , chr1-chr2+chr3);
	return 0;

}
