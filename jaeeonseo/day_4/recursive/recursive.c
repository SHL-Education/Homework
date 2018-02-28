#include <stdio.h>

int fib(int num)
{
	int result; 


  	if(num == 1 || num == 2)
	{
      		return 1;
	}
  	else
	{
		result = fib(num-1)+fib(num-2);
	
      		return result;
	}
}

int main(void)
{

  int result=0, final_val=0;
 
  printf("피보나치 수열의 항의 개수를 입력하시오:");
  
  scanf("%d", &final_val);
  
  result = fib(final_val);
  
  printf("%d번째 항의 수는 = %d\n", final_val, result);
  
  return 0;
}
