#include <stdio.h>


int main(void)
{
	int chr1='A', chr2 = 'B', chr3 = 'C';

	printf("A의 해당하는 수는 = %d", chr1);
	printf("소문자는 = %c, 숫자값:%d\n", chr1^32, chr1^32); //xor내용
	printf("A-B+C=%c\n", chr1-chr2+chr3);

	return 0;
}
