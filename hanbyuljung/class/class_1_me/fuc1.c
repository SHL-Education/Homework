#include<stdio.h>

float myfunc(int num1, int num2){
 // return num * 2;
  return num1*num2+3.3;
 // return num << 1;
}

int main(void){
	int num1 = 3, num2 = 6;
	float res;
	res = myfunc(num1,num2);
	printf("res=%f\n",res);
	
	return 0;
}
