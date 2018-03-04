#include <stdio.h>

float bbb(int n1, int n2)
{
	return 0.2*(n1 + n2);
}

float ccc(int n1, int n2)
{       
        return 0.1*(n1+n2); 
}

//float (*)(int,int) aaa(float(*)(int,int))
float (*aaa(float(*p2)(int, int)))(int, int)
{
        float res = p2(1,2);
        printf("%lf\n",res);
        return bbb;
}

void ddd(void)
{
	char string[] = "hello baby!";
        printf("%s\n", string);
}

// float (*)(int,int) (*)(float(*)(int,int)) test(void(*p1)(void))
float (*(*test(void(*p1)(void)))(float(*)(int, int)))(int, int)
{
        p1();     // ddd 대입
        return aaa;
}

int main(void)
{	
	float res;	
	res = test(ddd)(ccc)(1,3);
	
	printf("result of test = %lf\n",res);
	return 0;
}
