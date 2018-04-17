#include "89_load_test.h"

double get_runtime(tv start, tv end)
{
	end.tv_usec = end.tv_usec - start.tv_usec;
	end.tv_sec = end.tv_sec - start.tv_sec;
	end.tv_usec += end.tv_sec * 1000000;

#if DEBUG
	printf("runtime = %lf sec\n", end.tv_usec / 1000000.0);
#endif

	return end.tv_usec / 1000000.0;
}
