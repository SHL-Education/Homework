#include<stdio.h>

void aaa(void)
{
	printf("aaa called\n");

}

void (*bbb(void(*p)(void)))(void){

	p();
	printf("bbb valled\n");
	return aaa;
}

	


int main(void)
{
	bbb(aaa)();

	return 0;

}
