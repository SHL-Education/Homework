#include <stdio.h>

int LshiftOp(int val, int shiftArg)
{
	return val<<shiftArg;
}

int RshiftOp(int val, int shiftArg)
{
	return val>>shiftArg; 
}

int AndOpFunc(int arg1, int arg2)
{
	return arg1&arg2;
} 

int OrOpFunc(int arg1, int arg2)
{
	return arg1|arg2;
}

int XorOpFunc(int arg1, int arg2)
{
	return arg1^arg2;
}

int main(void)
{
	//quiz.1
	printf("quiz1: 6 << 4 = %d\n", LshiftOp(6, 4));


	//quiz.2
	printf("quiz2: 55 >> 3 = %d\n", RshiftOp(55,3));

	//quiz.3 AND
	printf("quiz3: 21 & 31 = %d\n", AndOpFunc(21, 31));

	//quiz.3 OR
	printf("quiz3: 21 | 31 = %d\n", OrOpFunc(21, 31));

	//quiz.3 XOR
	printf("quiz3: 21 ^ 31 = %d\n", XorOpFunc(21, 31));

	return 0;
}
