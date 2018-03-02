#include <stdio.h>

void aaa(void)
{

	printf("aaa called\n");

}

int number(void){

	printf("number called\n");
	return 7;
}

void (* bbb(void))(void){

		printf("bbb called\n");
		return aaa;
}

void ccc(void(*p)(void)){

	printf("ccc:I can call aaa \n");
	p();
}
int (* ddd(void))(void){
	printf("ddd: I can call number\n");
	return number;
}


int main(void)
{
		int res;


		bbb()();
		ccc(aaa);
		res=ddd()();
		printf("res =%d \n",res);

		return 0;
}
