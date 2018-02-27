#include <stdio.h>

int main(void)
{
	char str1[5] = "AAA";
	char str2[] = "BBB";
	char str3[] = {'A', 'B', 'C'};
	char str4[] = {'A', 'B', 'C', '\0'};

	printf("str1 = %s\n", str1);
	printf("str1 = %s\n", str2);
	printf("str1 = %s\n", str3);
	printf("str1 = %s\n", str4);

	str1[0] = 'E';
	str1[1] = 'H';
	printf("str1 = %s\n", str1);

	return 0;
}
	
