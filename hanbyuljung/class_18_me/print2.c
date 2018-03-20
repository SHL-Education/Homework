#include<fcntl.h>
#include<unistd.h>

int main(void)
{
	int nr;
	char buf[1024] = {0};

	nr = read(0, buf, sizeof(buf));
	write(1, buf, nr);
	return 0;
}
