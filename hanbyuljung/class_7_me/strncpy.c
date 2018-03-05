#include<stdio.h>
#include<string.h>

int main(int argc, char ** argv){
	char src[20] = "abcdef";
	char dst[20];
	strncpy(dst, src, 3);
	printf("dst = %s \n",dst);

	return 0;
}
