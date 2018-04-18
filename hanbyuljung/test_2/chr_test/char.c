#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUFFER	10
char buf_in[MAX_BUFFER];
char buf_out[MAX_BUFFER];

int main(void)
{
	int fd, i, c,res1 = 0;
	int res2 =1;
	char s[128];
	if( (fd = open("/dev/mydevicefile", O_RDWR)) <0){
		perror("open error");
		return -1;
	}

	for(i= 1 ; i<11; i++){
		res1 += i;
	}
	for(i= 1 ; i<6; i++){
		res2 *= i;
	}

	for(i =0; i<MAX_BUFFER; i++){
		fprintf(stderr, "%c\n",buf_in[i]);
	}

	fprintf(stderr, "\n");
	sprintf(s,"%d", res1);
	read(fd, s, MAX_BUFFER);
	write(fd, s, MAX_BUFFER);
	s[128] = 0;
	sprintf(s,"%d", res2);
	read(fd, s, MAX_BUFFER);
	write(fd, s, MAX_BUFFER);

	fprintf(stderr, "\n");

	close(fd);
	return 0;
}

