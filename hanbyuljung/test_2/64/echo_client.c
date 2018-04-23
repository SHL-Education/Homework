#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<string.h>


typedef struct sockaddr_in si;
typedef struct sockaddr * sap;

#define BUF_SIZE	1024

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main(int argc, char **argv)
{
	int sock , str_len;
	si serv_addr;
	char msg[32];
	char *m = "Input Message(q to quit): ";

	if(argc != 3)
	{
		printf("use: %s <IP> <port> \n", argv[0]);
		exit(1);
	}

	sock = socket(PF_INET, SOCK_STREAM, 0);

	if(sock == -1)
		err_handler("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if(connect(sock, (sap)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("connect() error");
	else
		puts("Connected ....");

	for(;;)
	{
		if(!strcmp(msg, "q\n") || !strcmp(msg, "g\n"))
			break;
		
		write(sock, "hi", strlen(msg));
		str_len = read(sock, msg, BUF_SIZE -1);
		
		if(str_len == -1)
			err_handler("read() error!");

		msg[str_len] = 0;
		printf("msg from serv: %s\n", msg);
		sleep(10);

	}
	close(sock);
	return 0;
}

