#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

typedef struct sockaddr_in si;
typedef struct sockaddr * sap;

#define BUF_SIZE	32

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main(int argc, char **argv)
{
	char buf[BUF_SIZE] ={0};
	int fd, sock, read_cnt;
	si serv_addr;
	
	if(argc != 3)
	{
		printf("use: %s <IP> <port>\n", argv[0]);
		exit(1);
	}

	fd = open("receive.txt", O_CREAT | O_WRONLY);
	sock = socket(PF_INET, SOCK_STREAM, 0);

	if(sock == -1)
		err_handler("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	//  connect 신호가 날라오면 서버에서 accept 시 연결이 된다.
	if(connect(sock, (sap)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("connect() error");
	else
		puts("Connected ......");

	while((read_cnt = read(sock ,buf, BUF_SIZE)) != 0)
		write(fd, buf, read_cnt);

	puts("Received File Data");
	write(sock, "Thack you", 10);
	close(fd);
	close(sock);
	return 0;

}
