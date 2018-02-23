#include<stdio.h>

float myfunc(int num1, int num2){
 // return num * 2;
  return num1*num2+3.3;
 // return num << 1;
}

float test(int a , int b){
	printf("I can call myfunc()\n");
	return myfunc(a	,b);
}

int main(void){
	int num1 = 3, num2 = 6;

	printf("res=%1f\n",test(num1, num2));
	
	return 0;
}
