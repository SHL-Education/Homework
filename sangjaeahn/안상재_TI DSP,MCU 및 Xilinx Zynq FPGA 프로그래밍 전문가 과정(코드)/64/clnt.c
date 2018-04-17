#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>
#include <signal.h>

typedef struct sockaddr_in si;
typedef struct sockaddr * sap;

#define BUF_SIZE 32

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

void read_routine(int sock, char *buf)
{
	char buf1[] = "hello";
	while(1)
	{
		int str_len;
	
		str_len = read(sock, buf, BUF_SIZE);
		if(!strcmp(buf, buf1))
		{
			printf("message from server : %s\n\n", buf);
		}
	}
}

void write_routine(int sock, char *buf)
{
	char buf1[] = "hi";

	for(;;)
	{
		sleep(1);
		write(sock, buf1, strlen(buf1));
		
	}
}

int main(int argc, char **argv)
{
	pid_t pid;
	int i, sock;
	si serv_addr;
	char buf[BUF_SIZE] = {0};	

	if(argc != 3)
	{
		printf("use : %s <IP> <PORT>\n", argv[0]);
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
		puts("Connected ......");
	
	pid = fork();
	
	if(pid == 0)
		write_routine(sock, buf);
	else
		read_routine(sock, buf);	// 부모는 read
		
	close(sock);
	
	return 0;
}
