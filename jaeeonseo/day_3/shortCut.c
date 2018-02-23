#include <stdio.h>

int main(void)
{
	int shortcut1 =3, shortcut2 = 0;
	int result;

	result = (shortcut2 && ++shortcut1);
	printf("shortcut2 && shortcut1, result= %d\n", result);

	result = (shortcut1 || ++shortcut2);
	printf("shortcut1 || ++shortcut2, result = %d\n", result);

	return 0;
}
