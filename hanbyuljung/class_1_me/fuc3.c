#include<stdio.h>

int myfunc(int num1, int num2, int num3, int num4){
 // return num * 2;
  return num1*num2+num3-num4;
 // return num << 1;
}

int test(int a , int b, int c, int d){
	printf("I can call myfunc()\n");
	return myfunc(a	,b, c, d);
}

int main(void){
	int num1 = 3, num2 = 6, num3=20, num4=8;

	printf("res=%d\n",test(num1, num2,num3,num4));
	
	return 0;
}
