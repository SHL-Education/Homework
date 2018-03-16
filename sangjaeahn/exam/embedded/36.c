#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int game(int me, int com)
{
        if(me == 0)
        {
                if(com == 1)
                        return 'w';
                else
                        return 'l';
        }
        else if(me == 1)
        {
                if(com == 0)
                        return 'l';
                else
                        return 'w';
        }
        else if(me == 2)
        {
                if(com == 0)
                        return 'w';
                else
                        return 'l';
        }
}

int start(void)
{
	int me, com;
	
	while(1)
	{
		com = rand() % 3;
		scanf("%d", &me);
		
		if(me != com)		
			break;
	}

	return game(me, com);
}

int main(void)
{
	srand(time(NULL));
	
	int result = start();
	
	if(result == 'w')
	{
		printf("i'm win!\n");
	}
	else if(result == 'l')
	{
		printf("i'm loseㅠㅠ\n");
	}

	return 0;
}
