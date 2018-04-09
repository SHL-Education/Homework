#include<stdio.h>


typedef enum __packet{

	ATTACK,
	DEFENCE,
	HOLD,
	STOP,
	SKILL,
	REBIRTH,
	DEATH =44,
	KILL,
	ASSIST

}packet;



int main(void)
{
	packet packet;


	for(packet = ATTACK; packet <= REBIRTH; packet++)
			printf("enum num = %d\n", packet);
	for(packet = DEATH; packet <= ASSIST; packet ++)
			printf("enum num = %d \n",packet);
	
	return 0;

}
