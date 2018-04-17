#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <sys/socket.h>

typedef struct sockaddr_in si;
typedef struct sockaddr * sap;

#define BUF_SIZE 32

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

void read_childproc(int sig)
{
	pid_t pid;
	int status;
	pid = waitpid(-1, &status, WNOHANG);	// 자식 프로세스 처리
	printf("Removed proc id : %d\n", pid);
}

int main(int argc, char **argv)
{
	int serv_sock, clnt_sock;
	si serv_addr, clnt_addr;
	pid_t pid;
	struct sigaction act;
	socklen_t addr_size;
	int str_len=0, state;
	char buf[BUF_SIZE] = {0};
	char buf1[] = "hello";
	char buf2[] = "hi";

	if(argc != 2)
	{
		printf("use : %s <port>\n", argv[0]);
		exit(1);
	}

	act.sa_handler = read_childproc;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	state = sigaction(SIGCHLD, &act, 0);

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);

	if(serv_sock == -1)
		err_handler("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));
	
	if(bind(serv_sock, (sap)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("bind() error");
	
	if(listen(serv_sock, 5) == -1)
		err_handler("listen() error");

	for(;;)
	{
		addr_size = sizeof(clnt_addr);
		clnt_sock = accept(serv_sock, (sap)&clnt_addr, &addr_size);
		
		if(clnt_sock == -1)
			continue;
		else
			puts("New Client Connected ...");

		pid = fork();
		if(pid == -1)
		{
			close(clnt_sock);
			continue;
		}
		if(pid == 0)
		{
			close(serv_sock);

			for(;;)
			{
				str_len = read(clnt_sock, buf, BUF_SIZE);
				if(!strcmp(buf, buf2) && str_len)	// "hi"랑 같다면
				{
					printf("message from client : %s\n\n", buf);
					write(clnt_sock, buf1, sizeof(buf1));	//"hello" 전송
				}
			}
			
			close(clnt_sock);
			puts("Client Disconnected ... ");
			return 0;
		}
		else 
			close(clnt_sock);
	}
	close(serv_sock);	
	return 0;
}
