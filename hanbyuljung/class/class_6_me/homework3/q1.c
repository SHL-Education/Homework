#include<stdio.h>

void print_even_arr_elem(char *str)
{
	int i;
	for(i=0; str[i]; i++)
	{
		if(!(str[i]%2))
		{

			printf("res= %d: %c\n",str[i],str[i]);			
		}
	}

}


int main(void)
{
	char str[32]="Hello Embedded World!\n";

	print_even_arr_elem(str);

	return 0;
}
