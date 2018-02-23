#include<stdio.h>

int main(void)
{
	int shortcut1 = 3, shortcut2 =0;
	int result;

	result = (shortcut2 && ++shortcut1);
	printf("shortcut1 = %d\n", shortcut1);

	result = (shortcut1 || ++ shortcut2);
	printf("shortcut2 = %d\n", shortcut2);
	return 0;

}
