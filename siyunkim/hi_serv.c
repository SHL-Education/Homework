#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <sys/socket.h>

typedef struct sockaddr_in	si;
typedef struct sockaddr	*	sap;

#define BUF_SIZE	32

//char h[BUF_SIZE]="Hi clnt";

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
	pid = waitpid(-1, &status, WNOHANG);
//프로세스 올떄까지 기다렸다가 리무브드
	printf("Removed proc id: %d\n",pid);
}

int main(int argc, char **argv)
{
	int serv_sock, clnt_sock;
	si serv_addr, clnt_addr;
	pid_t pid;
	struct sigaction act;
	socklen_t addr_size;
	int str_len, state;
	char buf[BUF_SIZE]={0};
	char h[BUF_SIZE]="Hi clnt";
		
	if(argc !=2)
	{
		printf("use: %s <port>\n", argv[0]);
		exit(1);
	}

	act.sa_handler = read_childproc;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	state = sigaction(SIGCHLD, &act, 0);//시그차일드 오면
	
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
			puts("New Client Connected...");
		pid = fork();//프로세스 생성
		if(pid == -1)//오류
		{
			close(clnt_sock);
			continue;
		}
		if(pid == 0)//자식
		{
			close(serv_sock);//서버소켓 닫는다.
			
		//	while((str_len = read(clnt_sock, buf, BUF_SIZE)) !=0)
			for(;;)
			{	
				read(clnt_sock, buf, BUF_SIZE);
				write(1,"msg from clnt : ",16);
				write(1,buf,strlen(buf));
				write(clnt_sock, h, strlen(h));
			}
	
			close(clnt_sock);//read가 block니까 종료될일 없음.
			puts("Client Disconnected ...");
			return 0;
		}
		else
			close(clnt_sock);//클라이언트 소켓 닫고 새로운 클라이언트 올떄까지 어셉트에서 기다림
	}
	close(serv_sock);
	
	return 0;
}
//여러사람이 접속했을때 갱신이 빨리 안됨.
