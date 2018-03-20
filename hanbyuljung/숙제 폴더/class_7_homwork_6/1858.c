#include <stdio.h>


//float(*(*test(void(*)(void)))(float (*)(int, int)))(int,int);

//float test(void(*)(void)) (float (*)(int, int)) 
//1.  float (*)(int,int) (*)( ) test(void(*)(void)) (float (*)(int, int)

//float ( *test(void(*)(void)) )( float (*)(int,(int)) )
//2.  float (*)(int, int) (*)(float (*)(int, int)) test(void(*)(void))

float pof_test1(int n1, int n2)
{
	return n1+n2*2.7;
}
float pof_test2(int n1, int n2)
{

	return n1 + n2 +3.3 ;
}

void *message(void)
{
	printf("이벤트가 발생하여 실행합니다.");

}


//float(*(*test(void(*)(void)))(float (*)(int, int)))(int,int)
//float (*)(int, int) (*)(float (*)(int, int)) test(void(*)(void))

// float (*(*)(float (*)(int, int)))(int,int)
// float (*)(int, int) (*)(float (*)(int,int))
float (*(*test(void (*p3)(void)))(float (*p2)(int, int)))(int,int)
{
	float res;
	p3();
	res =  p2(5,5);
	printf("res = %f",res);
	return 0;
}

//float (*)(int, int) (*)(float (*)(int, int)) test(void(*)(void));
int main (void)
{	
	float res=0;
	
	test()(5,5)(4,4);
	printf("test =%f", res);

	return 0;
}
