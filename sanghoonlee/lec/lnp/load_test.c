#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct timeval	tv;

void get_runtime(tv start, tv end)
{
	end.tv_usec = end.tv_usec - start.tv_usec;
	end.tv_sec = end.tv_sec - start.tv_sec;
	end.tv_usec += end.tv_sec * 1000000;

	printf("runtime = %lf sec\n", end.tv_usec / 1000000.0);
}

int main(void)
{
	unsigned int i, cnt = 0;
	tv start, end;

	gettimeofday(&start, NULL);

	for(i = 0; i < 777777777; i++)
		cnt++;

	gettimeofday(&end, NULL);

	get_runtime(start, end);

	return 0;
}
