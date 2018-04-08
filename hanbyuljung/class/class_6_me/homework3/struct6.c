#include <stdio.h>


void aaa(void)
{
	printf("aaa called\n");
}

void bbb(void(*p)(void)){
	p();
	printf("bbb called\n");

}

int main(void){
	bbb(aaa);
	return 0;
}

