#include<stdio.h>

int change(char *a ,char *b)
{
		int i;
		char temp[sizeof(a)];
		for(i=0;i<sizeof(a);i++){
				temp[i]=a[i];
				a[i]=b[i];
				b[i]=temp[i];
		}
		printf("%s\n",a);
		printf("%s\n",b);

}

int main(void)
{

		char str1[]="devil";
		char str2[]="angel";

		printf("%s\n",str1);
		printf("%s\n",str2);
		change(str1, str2);
		return 0;

}

