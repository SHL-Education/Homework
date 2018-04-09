#include<stdio.h>
#include<string.h>


int main(int argc, char ** argv)
{
	char src[20]= "made in korea";
	char dst[20]= "made in china";
	if (!strncmp(src, dst, 8))
			printf("src, dst는 서로 같음 \n");
	else
			printf("src, dst는 서로다름\n");
	

	return 0;

}
