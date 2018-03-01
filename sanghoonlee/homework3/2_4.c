#include <stdio.h>

void pointer_juggling(void)
{
	int n1 = 2, n2 = 4, n3 = 7;
	int *tmp = NULL;
	int *n_p[3] = {&n1, &n2, &n3};
	int **npp = NULL;

	int i = 0, j = 0;;

	printf("n1 = %d\n", *n_p[0]);
	printf("n2 = %d\n", *n_p[1]);
	printf("n3 = %d\n\n", *n_p[2]);

	for(;;)
	{
		npp = &n_p[i];
		tmp = *npp;
		*npp = n_p[i + 1];
		n_p[i + 1] = n_p[i + 2];
		n_p[i + 2] = tmp;

		printf("n1 = %d\n", *n_p[0]);
		printf("n2 = %d\n", *n_p[1]);
		printf("n3 = %d\n\n", *n_p[2]);

		if(j++ == 3)
			break;
	}
}

int main(void)
{
	pointer_juggling();
	return 0;
}
