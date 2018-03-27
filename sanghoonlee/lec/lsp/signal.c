#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>

void sig_handler(int signo)
{
	printf("You lose! Input should be within 1 second!\n");
	exit(0);
}

void make_game(int *data)
{
	*data = rand() % 100 + 1;
}

bool check_correct(int data, int cmp)
{
	if(data == cmp)
		return true;
	else
		return false;
}

void start_game(int data)
{
	char buf[32] = {0};
	bool fin;
	int i, cmp;

	for(i = 0; i < 10; i++)
	{
		signal(SIGALRM, sig_handler);
		printf("숫자를 맞춰봐!\n");
		alarm(1);
		read(0, buf, sizeof(buf));
		alarm(0);
		cmp = atoi(buf);

		fin = check_correct(data, cmp);

		if(fin)
		{
			printf("You Win!!!\n");
			exit(0);
		}
		else
		{
			if(data > cmp)
				printf("%d 보다 크다\n", cmp);
			else
				printf("%d 보다 작다\n", cmp);
		}
	}

	printf("You Lose!!! You Babo\n");
}

int main(void)
{
	int data;

	srand(time(NULL));
	make_game(&data);

	start_game(data);

	return 0;
}
