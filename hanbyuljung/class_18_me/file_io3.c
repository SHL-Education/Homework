#include<fcntl.h>
#include<unistd.h>

int main(void)
{
	int filedes1, filedes2;
	// refresh 되려면 한번 밀고 작업 하는 o_trunc 를 써야 한다/
	filedes1 = open("data1.txt",O_WRONLY |O_CREAT|O_TRUNC,0644);
	filedes2 = creat("data2.txt",0644);
	close(filedes1);
	close(filedes2);

	return 0;
}
